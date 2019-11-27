#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <elf.h>
#include <unistd.h>
#include <sys/mman.h>

#include <cassert>
#include <cstdio>
#include <cstring>
#include <byteswap.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: %s <elf-binary>\n", argv[0]);
    return 1;
  }
  FILE *pyfile = fopen(argv[1], "r");
  if (pyfile == nullptr) {
    return 1;
  }
  if (fseek(pyfile, 0, SEEK_END)) {
    fclose(pyfile);
    return 1;
  }
  long pyfile_size = ftell(pyfile);

  char *pybytes = (char*)mmap(nullptr, (size_t)pyfile_size, PROT_READ, MAP_PRIVATE,
                       fileno(pyfile), 0);
  if (pybytes == nullptr) {
    fclose(pyfile);
    perror("mmap()");
    return 1;
  }
  fclose(pyfile);
  //printf("%p\n", pybytes);

  const unsigned char expected_magic[] = {ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3};
  Elf32_Ehdr elf_hdr;
  memmove(&elf_hdr, pybytes, sizeof(elf_hdr));
  printf("EP:\t%X\n", elf_hdr.e_entry);
#ifdef DEBUG
  printf("file size: %zd\n", pyfile_size);
  printf("program header offset: %zd\n", elf_hdr.e_phoff);
  printf("program header num: %d\n", elf_hdr.e_phnum);
  printf("section header offset: %zd\n", elf_hdr.e_shoff);
  printf("section header num: %d\n", elf_hdr.e_shnum);
  printf("section header string table: %d\n", elf_hdr.e_shstrndx);

  size_t string_offset = elf_hdr.e_shstrndx;
  printf("string offset at %zd\n", string_offset);
  printf("\n");
#endif
  char *cbytes = (char *)pybytes;
  for (uint16_t i = 0; i < elf_hdr.e_phnum; i++) {
    size_t offset = elf_hdr.e_phoff + i * elf_hdr.e_phentsize;
    Elf32_Phdr phdr;
    memmove(&phdr, pybytes + offset, sizeof(phdr));
#ifdef DEBUG
    printf("PROGRAM HEADER %d, offset = %zd\n", i, offset);
    printf("========================\n");
    printf("p_type = ");
    switch (phdr.p_type) {
      case PT_NULL:
        puts("PT_NULL");
        break;
      case PT_LOAD:
        puts("PT_LOAD");
        break;
      case PT_DYNAMIC:
        puts("PT_DYNAMIC");
        break;
      case PT_INTERP:
        puts("PT_INTERP");
        break;
      case PT_NOTE:
        puts("PT_NOTE");
        break;
      case PT_SHLIB:
        puts("PT_SHLIB");
        break;
      case PT_PHDR:
        puts("PT_PHDR");
        break;
      case PT_LOPROC:
        puts("PT_LOPROC");
        break;
      case PT_HIPROC:
        puts("PT_HIPROC");
        break;
      case PT_GNU_STACK:
        puts("PT_GNU_STACK");
        break;
      default:
        printf("UNKNOWN/%d\n", phdr.p_type);
        break;
    }
    printf("p_offset = %zd\n", phdr.p_offset);
    printf("p_vaddr = %zd\n", phdr.p_vaddr);
    printf("p_paddr = %zd\n", phdr.p_paddr);
    printf("p_filesz = %zd\n", phdr.p_filesz);
    printf("p_memsz = %zd\n", phdr.p_memsz);
    printf("p_flags = %d\n", phdr.p_flags);
    printf("p_align = %lu\n", phdr.p_align);
    printf("\n");
#endif
    uint32_t* segment_content = (uint32_t*)(pybytes + phdr.p_offset);
    uint32_t addr_aligned = phdr.p_vaddr;//(phdr.p_vaddr & ((phdr.p_align & phdr.p_align == 0) - 1)) + phdr.p_align; 
    for(int wordn = 0; wordn < phdr.p_memsz / 4; wordn++)
    {
		//printf("%X\t%08X\n", addr_aligned + wordn * 4, __bswap_32 (segment_content[wordn]));
		printf("%X\t%08X\n", addr_aligned + wordn * 4, segment_content[wordn]);
	} 
  }

  printf("\n");
  return 0;
}
