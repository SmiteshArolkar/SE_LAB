SECTION .DATA
      hello db "Hello World" , 10
      hellolen equ $-hello
      name db "Smitesh Arolkar" ,10
      namelen equ $-name
SECTION .TEXT
      GLOBAL _start

     _start:
            mov eax,4
            mov ebx,1
            mov ecx,hello
            mov edx,hellolen
            int 80h

            mov eax,4
            mov ebx,1
            mov ecx,name
            mov edx,namelen
            int 80h

            mov eax,1
            mov ebx,0
            int 80h