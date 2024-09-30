section .data
  msg db '<`)   //<`)// (\\   "  1  (>/  (/ (//   \'

section .text
  global _start

_start:
  mov rsi, msg
  mov rax, 1
  mov rdi, 1
  mov rdx, 5
  syscall

  mov rax, 60
  xor rdi, rdi
  syscall
