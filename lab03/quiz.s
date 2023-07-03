# Assuming h is register a1
# Assuming g is register a2

# h < g ->>>> execute break1 instructions
blt a1, a2, break1
addi a1, a1, -1

break1:
    addi a2, a2, 1

# .................................................

# h >= g ->>>> execute break2 instructions
bge a1, a2, break2
li a1, 0

break2:
    li a2, 0

# .................................................


