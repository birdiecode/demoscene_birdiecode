section .data
  msg db '<`)   //<`)// (\\   "  1  (`>/  (/ (//   \'
  frames db 0, 34, 21, 3, 26, 21, 3, 24, 21, 8, 30, 21, 0, 13, 38, 8, 30, 17, 0, 13, 17
  ;        |    0     |     3    |    6     |   9      |   12     |    15    |   18
  frame db 0,3,6,3,6,3,0,9,12,15,18,15,18,15,18,0
  birdiecode db "birdiecode", 10

section .text
  global _start

_start:
  mov r9, 16
animation_loop:
  mov rdx, 3
; region print frame
print_loop:
  mov rbx, rdx            ; Сохраняем значение счётчика в регистр rdx

  mov rdi, frames
  mov r8, frame           ; Загружаем значение из адреса frame в регистр r8
  add r8, 16              ; Необходима инверсия значения счетчика цикла `animation_loop`.
  sub r8, r9              ; Далее, выполняется вычитание счетчика `animation_loop` для получения инверсии значения.

  movzx rsi, byte [r8]    ; Загружается значение из адреса `frame`, с учётом временного сдвига, в регистр `rsi`.
  add rdi, rsi            ; Указатель смещается в массив на индекс, заданный значением в регистре `rsi`. На данном этапе регистр `rsi` больше не используется.

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

  ; TODO: Реализовать задержку на 250 миллисекунд.
  ; TODO: Реализовать перемещение курсора на 3 строки вверх.

  mov rdx, r9
  dec rdx
  mov r9, rdx
  jnz animation_loop

  mov rax, 60
  xor rdi, rdi
  syscall
