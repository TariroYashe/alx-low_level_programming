#include "main.h"

/**
* display_error - Func to display an error message and exit with status 98
* @message: error message to be displayed
*/
void display_error(const char *message)
{
fprintf(stderr, "%s\n", message);
exit(98);
}

/**
* display_elf_header- Function to display the ELF header
* information
*@header: information contained in the header
*/
void display_elf_header(const Elf64_Ehdr *header)
{
int i;
/* Display the ELF Header */
printf("ELF Header:\n");

/* Display the Magic bytes */
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", header->e_ident[i]);
if (i < EI_NIDENT - 1) printf(" ");
}
printf("\n");
/* Display the Class of the ELF file (32-bit or 64-bit) */
printf("  Class:                             ");
switch (header->e_ident[EI_CLASS])
{
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %d>\n", header->e_ident[EI_CLASS]);
break;
}
/* Display the Data encoding (little or big endian) */
printf("  Data:                              ");
switch (header->e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %d>\n", header->e_ident[EI_DATA]);
break;
}
/* Display the Version */
printf("  Version:		%d (current)\n", header->e_ident[EI_VERSION]);

/* Display the OS/ABI */
printf("  OS/ABI:                            ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
default:
printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
break;
}
/* Display the ABI Version */
printf("  ABI Version:		%d\n", header->e_ident[EI_ABIVERSION]);
/* Display the Type of the ELF file (Executable, Dynamic, etc.) */
printf("  Type:                              ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (Unknown Type)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
default:
printf("<unknown: %d>\n", header->e_type);
break;
}
/* Display the Entry point address */
printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
* main - Entry point
* @argc: count the number of arguments
* @argv: An array of strings (char pointers) that
* contains the actual command-line arguments
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
char *filename;
int fd;
Elf64_Ehdr header;
ssize_t bytes_read;
/* Check for the correct number of command line arguments */
if (argc != 2)
display_error("Usage: elf_header elf_filename");
/* Get the ELF filename from the command line argument */
filename = argv[1];
/* Open the ELF file for reading */
fd = open(filename, O_RDONLY);
if (fd == -1)
display_error("Error: Unable to open file");
/* Read the ELF header from the file */
bytes_read = read(fd, &header, sizeof(header));
/* Check if the file is a valid ELF file */
if (bytes_read != sizeof(header) || header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
{
display_error("Error: Not an ELF file");
}
/* Display the ELF header information */
display_elf_header(&header);
/* Close the file */
close(fd);
return (0);
}
