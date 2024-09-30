section .data
  msg db '<`)   //<`)// (\\   "  1  (`>/  (/ (//   \'
  frames db 0, 34, 21, 3, 26, 21, 3, 25, 21, 8, 30, 21, 0, 13, 38, 8, 30, 17, 0, 13, 17
  frame db 0
  birdiecode db "birdiecode", 10

section .text
  global _start

_start:
  mov rdx, 3

; region print frame
print_loop:
  mov rbx, rdx            ; Сохраняем значение счётчика в регистр rdx

  mov rdi, frames
  movzx rsi, byte [frame] ; Загружаем значение из адреса frame в регистр rsi
  add rdi, rsi            ; Смещаем указатель в массиве на индекс, указанный в rsi. На этом этапе rsi больше не нужен

  add rdi, 3              ; Так как счётчик уменьшается, а требуется инверсия, сначала прибавляем максимальное значение
  sub rdi, rbx            ; Затем вычитаем счётчик, чтобы инвертировать значение

  movzx rax, byte [rdi]   ; Получаем значение из массива frames, то есть начальный адрес frames плюс смещение frame
  mov rsi, msg            ; Записываем в rsi адрес msg
  add rsi, rax            ; Сдвигаемся на значение из массива

  mov rax, 1
  mov rdi, 1
  mov rdx, 5
  syscall

  ; new line
  mov rax, 1
  mov rdi, 1
  mov rdx, 1
  mov rsi, birdiecode
  add rsi, 10
  syscall

  mov rdx, rbx            ; Возвращаем значение счётчика на место
  dec rdx                 ; Уменьшаем счетчик
  jnz print_loop
; endregion print frame
  ; Выводим никнейм
  mov rax, 1
  mov rdi, 1
  mov rdx, 11
  mov rsi, birdiecode
  syscall

  mov rax, 60
  xor rdi, rdi
  syscall
