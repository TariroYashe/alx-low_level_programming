#include "main.h"

/**
* main - Entry point
* @argc: count the number of arguments
* @argv: An array of strings (char pointers) that
* contains the actual command-line arguments
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
int fd;
Elf64_Ehdr *header;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
return (1);
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
perror("Error opening file");
return (1);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
perror("Error allocating memory");
close_elf(fd);
return (1);
}
if (read(fd, header, sizeof(Elf64_Ehdr)) == -1)
{
perror("Error reading file");
free(header);
close_elf(fd);
return (1);
}
elf_check(header);
printf("ELF Header:\n");
display_magic(header);
display_class(header);
display_data(header);
display_version(header);
display_osabi(header);
display_abi(header);
display_type(header);
display_entry(header);
free(header);
close_elf(fd);
return (0);
}

/**
* elf_check - Function to check if the file is an ELF file
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure
*/
void elf_check(Elf64_Ehdr *header)
{
if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}

/**
* display_magic - Function to print the magic numbers of the ELF header
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure
*/
void display_magic(Elf64_Ehdr *header)
{
int i;
printf(" Magic: ");
for (i = 0; i < SELFMAG; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
}

/**
* display_class - Function to print the class (32-bit or 64-bit) of the ELF
* header
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure
*/
void display_class(Elf64_Ehdr *header)
{
printf(" Class: ");
switch (header->e_ident[EI_CLASS])
{
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
}
}

/**
* display_data - Function to print the data format (endianess) of the ELF
* header
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure.
*/
void display_data(Elf64_Ehdr *header)
{
printf(" Data: ");
switch (header->e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
}
}

/**
* display_version - Function to print the ELF version
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure.
*/
void display_version(Elf64_Ehdr *header)
{
printf(" Version: %d (current)\n", header->e_ident[EI_VERSION]);
}

/**
* display_osabi - Function to print the operating system and ABI (Application
* Binary Interface) of the ELF header
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure.
*/
void display_osabi(Elf64_Ehdr *header)
{
printf(" OS/ABI: ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
}
}

/**
* display_abi - Function to print the ABI version
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure.
*/
void display_abi(Elf64_Ehdr *header)
{
printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
}

/**
* display_type - Function to print the type of the ELF file
* (e.g.executable, shared object, core dump)
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure.
*/
void display_type(Elf64_Ehdr *header)
{
printf(" Type: ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", header->e_type);
}
}

/**
* display_entry - Function to print the entry point address of the ELF file
* @header: is a pointer variable that will hold the memory address of an
* Elf64_Ehdr structure.
* Description: This function will display the entry point address as part of
* the ELF header analysis when you run the program.
*/
void display_entry(Elf64_Ehdr *header)
{
printf(" Entry point address: %#lx\n", header->e_entry);
}

/**
* close_elf - Function to close the ELF file
* @elf: the file descriptor of the ELF file
* Description: Closes the file descriptor associated with the ELF file,
* and if it fails to close, it exits with an error code.
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
perror("Error closing file");
exit(98);
}
}
