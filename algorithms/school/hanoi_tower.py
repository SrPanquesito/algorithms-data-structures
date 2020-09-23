# M.1.2 - Ejercicio de recursividad para materia Algoritmos y Estructuras de Datos.
# M.1.2 - Recursion excercise for Algorithms and Data Structures class.

# Diaz Reynoso Luis Gerardo - 1260642

# # Hanoi tower
# The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

# 1. Only one disk can be moved at a time.
# 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
# 3. No larger disk may be placed on top of a smaller disk.

rod1 = [3,2,1]
rod2 = []
rod3 = []

def hanoi(discos, aAct, aMov, aTemp):
    print(rod1)
    print(rod2)
    print(rod3)
    print("------------")

    if len(aAct) != 0:
        if len(aMov) == 0: aMov.append(aAct.pop())
        elif aAct[-1] < aMov[-1]: aMov.append(aAct.pop())
        else: aAct.append(aMov.pop())

    if len(aAct) != 0:
        if len(aTemp) == 0: aTemp.append(aAct.pop())
        elif aAct[-1] < aTemp[-1]: aTemp.append(aAct.pop())
        else: aAct.append(aTemp.pop())
    elif len(aTemp) != 0:
        aAct.append(aTemp.pop())
    else:
        return
    
    hanoi(discos, aMov, aTemp, aAct)

print("--- Inicio ---")
hanoi(len(rod1), rod1, rod2, rod3)

print("--- Fin ---")
print(rod1)
print(rod2)
print(rod3)