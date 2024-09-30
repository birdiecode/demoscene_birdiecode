# Demoscene birdiecode

Это маленькая ASCII art анимация созданная для изучения уменьшения размера исполняемого файла.

## Компиляция

```shell
nasm -f elf64 -o birdiecode.o birdiecode.s && ld -o birdiecode birdiecode.o
```

## Размер - 9184 B
