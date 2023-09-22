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


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *create_buffer(char *fyle);
void close_fyle(int file_descriptor);
int main(int argc, char *argv[]);
void display_error(const char *message);
void display_elf_header(const Elf64_Ehdr *header);

#endif
