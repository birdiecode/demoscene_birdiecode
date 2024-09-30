section .data
  msg db '<`)   //<`)// (\\   "  1  (`>/  (/ (//   \'
  frames db 0, 34, 21, 3, 26, 21, 3, 25, 21, 8, 30, 21, 0, 13, 38, 8, 30, 17, 0, 13, 17
  frame db 1

section .text
  global _start

_start:
  mov rdi, frames
  movzx rsi, byte [frame] ; Загружаем значение из адреса frame в регистр rsi
  add rdi, rsi            ; Смещаем указатель в массиве на индекс, указанный в rsi. На этом этапе rsi больше не нужен
  movzx rax, byte [rdi]   ; Получаем значение из массива frames, то есть начальный адрес frames плюс смещение frame
  mov rsi, msg            ; Записываем в rsi адрес msg
  add rsi, rax            ; Сдвигаемся на значение из массива

  mov rax, 1
  mov rdi, 1
  mov rdx, 5
  syscall

  mov rax, 60
  xor rdi, rdi
  syscall
