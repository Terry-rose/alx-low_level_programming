#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header(Elf64_Ehdr *header);
void error_exit(const char *msg);

int main(argc, argv)
    int argc;
    char *argv[];
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        error_exit("Usage: elf_header elf_filename\n");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        error_exit("Error: Can't open file\n");
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        error_exit("Error: Can't read ELF header\n");
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        error_exit("Error: Not an ELF file\n");
    }

    display_elf_header(&header);

    if (close(fd) == -1)
    {
        error_exit("Error: Can't close file descriptor\n");
    }

    return 0;
}

void display_elf_header(header)
    Elf64_Ehdr *header;
{
    int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; ++i)
    {
        printf("%02x%c", header->e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
    }

    printf("  Class:                             ELF%d\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
    printf("  Data:                              2's complement, %s endian\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
                                                          header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
                                                          header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
                                                          "<unknown>");
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s (%s)\n", header->e_type == ET_REL ? "REL (Relocatable file)" :
                                                          header->e_type == ET_EXEC ? "EXEC (Executable file)" :
                                                          header->e_type == ET_DYN ? "DYN (Shared object file)" :
                                                          header->e_type == ET_CORE ? "CORE (Core file)" : "Unknown",
                                                          header->e_type == ET_REL ? "Relocatable file" :
                                                          header->e_type == ET_EXEC ? "Executable file" :
                                                          header->e_type == ET_DYN ? "Shared object file" :
                                                          header->e_type == ET_CORE ? "Core file" : "Unknown");
    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

void error_exit(msg)
    const char *msg;
{
    dprintf(2, "%s", msg);
    exit(98);
}

