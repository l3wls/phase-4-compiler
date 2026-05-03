# mC Compiler - Generated MIPS Assembly
# Code Generator Phase 4

.data
i: .word 0
w: .space 40  # array[10]
a: .space 20  # array[5]

.text
.globl main

main:

# Assignment
li $t0, 15
move $t9, $t0
li $t0, 5
sll $t0, $t0, 2  # index * 4
la $t1, w
add $t1, $t1, $t0
sw $t9, 0($t1)

# Assignment
li $t0, 10
move $t9, $t0
li $t0, 0
sll $t0, $t0, 2  # index * 4
la $t1, a
add $t1, $t1, $t0
sw $t9, 0($t1)

# Assignment
li $t0, 5
sll $t0, $t0, 2  # index * 4
la $t1, w
add $t1, $t1, $t0
lw $t0, 0($t1)
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 0
sll $t0, $t0, 2  # index * 4
la $t1, a
add $t1, $t1, $t0
lw $t0, 0($t1)
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
add $t0, $t1, $t2
sw $t0, i

# Exit program
li $v0, 10
syscall
