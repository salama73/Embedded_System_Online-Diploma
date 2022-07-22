/* 
learn-in-depth
unit_2-lesson_3
eng.salama
*/

.section .vectors

.word   0x20001000        /* stackk top address */
.word   _reset            /* 1 resset  */
.word   vector_handler    /* 2 nmi falt */
.word   vector_handler    /* 3 hard falt */
.word   vector_handler    /* 4 mm falt */
.word   vector_handler    /* 5 bus falt */


.section .text

_reset:
	bl main
	b .

.thumb_func

vector_handler:
	b _reset