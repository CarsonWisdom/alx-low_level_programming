#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * print_error - Print error message to stderr and exit with status 98
 * @msg: Error message to print
 */
void print_error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Print information from ELF header
 * @header: Pointer to the ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("Magic:");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
	printf("Class:%s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data:%s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version:%d (current)\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("Tru64 UNIX\n");
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
	printf("ABI Version:%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown Type)\n");
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
	printf("Entry point address:%#lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point for the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 success, 98 error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Cannot read ELF header");

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
		print_error("Error: Not an ELF file");

	print_elf_header(&header);
	close(fd);
	return (0);
}
