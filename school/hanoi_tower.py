# M.1.2 - Ejercicio de recursividad para materia Algoritmos y Estructuras de Datos.
# M.1.2 - Recursion excercise for Algorithms and Data Structures class.

# Diaz Reynoso Luis Gerardo - 1260642

# # Hanoi tower
# The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

# 1. Only one disk can be moved at a time.
# 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
# 3. No larger disk may be placed on top of a smaller disk.

rod1 = [1,[5,4,3,2,1]]
rod2 = [2,[]]
rod3 = [3,[]]

def hanoi(discos, aAct, aMov, aTemp):
    # # Ver Listas en cada movimiento 
    # # See lists in each movement 
    # print(rod1[1])
    # print(rod2[1])
    # print(rod3[1])
    # print("----------------")

    print("Faltan ", discos, " pasos. ", end=" ")
 
    aMov[1].append(aAct[1].pop())
    print(aAct[0]," -> ",aMov[0])

    print("Faltan ", discos-1, " pasos. ", end=" ")

    if len(aAct[1]) != 0:
        if len(aTemp[1]) == 0: 
            aTemp[1].append(aAct[1].pop())
            print(aAct[0]," -> ",aTemp[0])
        elif aAct[1][-1] < aTemp[1][-1]: 
            aTemp[1].append(aAct[1].pop())
            print(aAct[0]," -> ",aTemp[0])
        else: 
            aAct[1].append(aTemp[1].pop())
            print(aTemp[0]," -> ",aAct[0])
    elif len(aTemp[1]) != 0:
        aAct[1].append(aTemp[1].pop())
        print(aTemp[0]," -> ",aAct[0])
    else:
        return
    
    hanoi(discos-2, aMov, aTemp, aAct)


# ~~~ MAIN ~~~
print("---- Inicio ----")
hanoi((2**len(rod1[1]))-1, rod1, rod2, rod3)

print("")
print("----- Fin -----")
print(rod1[1])
print(rod2[1])
print(rod3[1])