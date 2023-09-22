#ifndef MAIN_H
#define MAIN_H
#define BUF_SIZE 64

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *create_buffer(char *fyle);
void close_fyle(int file_descriptor);
int main(int argc, char *argv[]);
void display_magic(Elf64_Ehdr *header);
void elf_check(Elf64_Ehdr *header);
void display_class(Elf64_Ehdr *header);
void display_data(Elf64_Ehdr *header);
void display_version(Elf64_Ehdr *header);
void display_osabi(Elf64_Ehdr *header);
void display_abi(Elf64_Ehdr *header);
void display_type(Elf64_Ehdr *header);
void display_entry(Elf64_Ehdr *header);
void close_elf(int elf);

#endif
