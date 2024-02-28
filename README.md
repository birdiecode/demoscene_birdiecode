# Demoscene birdiecode

Это маленькая ASCII art анимация созданная для изучения уменьшения размера исполняемого файла.

## Компиляция

```shell
gcc -nostartfiles -nodefaultlibs -Os -s -fno-stack-protector -nostdlib -static main.c -o birdiecode
```

## Размер - 13160 B
