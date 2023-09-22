#include "main.h"

/**
* display_error - display an error message to stderr and exit with status98
* @message: The error message to print.
*/
void display_error(const char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);
exit(98);
}

/**
* print_elf_header - print ELFheader info from the provided file descriptor
* @file_descriptor: The file descriptor of the ELF file.
*/
void print_elf_header(int file_descriptor)
{
Elf64_Ehdr elf_header;
int i;

/* Read the ELF header */
if (read(file_descriptor, &elf_header,
			sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
display_error("Unable to read ELF header");

/* Check if it's a valid ELF file */
if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
elf_header.e_ident[EI_MAG3] != ELFMAG3)
display_error("Not an ELF file");

/* Print ELF header information */
printf("ELF Header:\n");

/* Print Magic */
printf(" Magic: ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", elf_header.e_ident[i]);
if (i < EI_NIDENT - 1)
printf(" ");
else
printf("\n");
}

/* Print Class */
printf(" Class: ");
switch (elf_header.e_ident[EI_CLASS])
{
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", elf_header.e_ident[EI_CLASS]);
}

/* Print Data Encoding */
printf(" Data: ");
switch (elf_header.e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", elf_header.e_ident[EI_DATA]);
}

/* Print Version */
printf(" Version: %d", elf_header.e_ident[EI_VERSION]);
if (elf_header.e_ident[EI_VERSION] == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");

/* Print OS/ABI */
printf(" OS/ABI: ");
switch (elf_header.e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", elf_header.e_ident[EI_OSABI]);
}

/* Print ABI Version */
printf(" ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);

/* Print Type */
printf(" Type: ");
switch (elf_header.e_type)
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
printf("<unknown: %x>\n", elf_header.e_type);
}

/* Print Entry Point Address */
printf(" Entry point address: %#lx\n", (unsigned long)elf_header.e_entry);
}


/**
* main - Entry point
* @argc: count the number of arguments
* @argv: An array of strings (char pointers) that
* contains the actual command-line arguments
*
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
int file_descriptor;
if (argc != 2)
display_error("Usage: elf_header elf_filename");

file_descriptor = open(argv[1], O_RDONLY);
if (file_descriptor == -1)
display_error("Can't open file");

print_elf_header(file_descriptor);

close(file_descriptor);
return (0);
}
