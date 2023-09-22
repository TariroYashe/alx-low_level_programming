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
int elf;
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
return (1);
}
elf = open(argv[1], O_RDONLY);
if (elf == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
return (1);
}

check_elf(elf);

printf("ELF Header:\n");
display_magic(elf);
display_class(elf);
display_data(elf);
display_version(elf);
display_os_abi(elf);
display_osabi(elf);
display_type(elf);
display_entry(elf);
close(elf);

return (0);
}
/**
* display_entry - Prints the entry point of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_entry(int elf)
{
Elf64_Ehdr header;

/* Read the ELF header into header */
if (read(elf, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
dprintf(STDERR_FILENO, "Error: Reading ELF entry point\n");
exit(98);
}

printf(" Entry point address: ");

if (header.e_ident[EI_DATA] == ELFDATA2MSB)
{
header.e_entry = ((header.e_entry << 8) & 0xFF00FF00) |
((header.e_entry >> 8) & 0xFF00FF);
header.e_entry = (header.e_entry << 16) | (header.e_entry >> 16);
}

/* Print the entry point address */
if (header.e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)header.e_entry);
else
printf("%#lx\n", header.e_entry);
}


/**
* display_osabi - display the ABI version of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_osabi(int elf)
{
unsigned char e_ident[EI_NIDENT];

/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Reading ELF ABI version\n");
exit(98);
}

printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
* display_type - display the type of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_type(int elf)
{
Elf64_Ehdr header;
unsigned int e_type;

/* Read the ELF header into header */
if (read(elf, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
dprintf(STDERR_FILENO, "Error: Reading ELF type\n");
exit(98);
}

e_type = header.e_type;

if (header.e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf(" Type: ");

/* Determine and print the ELF file type */
switch (e_type)
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
printf("<unknown: %x>\n", e_type);
}
}


/**
* check_elf - Checks if a file is an ELF file.
* @elf: The file descriptor of the ELF file.
*
* Description: If the file is not an ELF file, exit with code 98.
*/
void check_elf(int elf)
{
unsigned char e_ident[EI_NIDENT];
int index;
/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}

/* Verify the ELF magic numbers */
for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* display_magic - display the magic numbers of an ELF header.
* @elf: The file descriptor of the ELF file.
*
* Description: Magic numbers are separated by spaces.
*/
void display_magic(int elf)
{
unsigned char e_ident[EI_NIDENT];
int index;
/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Reading ELF magic numbers\n");
exit(98);
}

printf(" Magic: ");

/* Print the magic numbers */
for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* print_class - Prints the class of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_class(int elf)
{
unsigned char e_ident[EI_NIDENT];

/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Reading ELF class\n");
exit(98);
}

printf(" Class: ");

/* Determine and print the ELF class (32-bit or 64-bit) */
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* display_data -display the data of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_data(int elf)
{
unsigned char e_ident[EI_NIDENT];

/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Reading ELF data encoding\n");
exit(98);
}

printf(" Data: ");

/* Determine and print the data encoding (endianess) */
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_DATA]);
}
}

/**
* display_version - Prints the version of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_version(int elf)
{
unsigned char e_ident[EI_NIDENT];

/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Reading ELF version\n");
exit(98);
}

printf(" Version: %d", e_ident[EI_VERSION]);

/* Print the version information */
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
* display_os_abi - display the OS/ABI of an ELF header.
* @elf: The file descriptor of the ELF file.
*/
void display_os_abi(int elf)
{
unsigned char e_ident[EI_NIDENT];

/* Read the ELF identification bytes into e_ident */
if (read(elf, e_ident, EI_NIDENT) != EI_NIDENT)
{
dprintf(STDERR_FILENO, "Error: Reading ELF OS/ABI\n");
exit(98);
}

printf(" OS/ABI: ");

/* Determine and print the OS/ABI */
switch (e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}
