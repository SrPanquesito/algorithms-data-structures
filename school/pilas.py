# M.2.1 - Ejercicio de pilas y colas estáticas.

# Diaz Reynoso Luis Gerardo - 1260642

# Estructuras LIFO
# Un vector manipulado por dos pilas.

def push(data, tope, pila):
    if tope1+1 == tope2 or tope2-1 == tope1:
        print("\n\nERROR: Ambas pilas están llenas.\n\n")
    elif pila == 1:
        tope += 1
        v[tope] = data
    elif pila == 2:
        tope -= 1
        v[tope] = data
    else:
        print("\n\nERROR: Undefined.\n\n")
    return tope

def pop(tope, pila):
    if tope == -1 or tope == int(vectorSize):
        print("\n\nERROR: La pila #", pila ," está vacía.\n\n")
    elif pila == 1:
        print("\n\nEl valor que sale de la pila #1 es: ", v[tope], "\n\n")
        v[tope] = None
        tope -= 1
    elif pila == 2:
        print("\n\nEl valor que sale de la pila #2 es: ", v[tope], "\n\n")
        v[tope] = None
        tope += 1
    else:
        print("\n\nERROR: Undefined.\n\n")
    return tope

def mostrar(tope, pila):
    if tope == -1 or tope == int(vectorSize):
        print("\n\nERROR: La pila #", pila ," está vacía.\n\n")
    elif pila == 1:
        print("\n\nPila #1:")
        while tope > -1:
            print(v[tope], ", ", end='')
            tope -= 1
        print("\n\n")
    elif pila == 2:
        print("\n\nPila #2:")
        while tope < int(vectorSize):
            print(v[tope], ", ", end='')
            tope += 1
        print("\n\n")
    else:
        print("\n\nERROR: Undefined.\n\n")

def menu():
    global tope1, tope2, v
    op = 0
    while op != 7:
        print( "~ ~ ~ ~ ~ ~ ~ ~ ~ Menu ~ ~ ~ ~ ~ ~ ~ ~ ~")
        print("1) Push - Pila 1")
        print("2) Push - Pila 2")
        print("3) Pop - Pila 1")
        print("4) Pop - Pila 2")
        print("5) Mostrar - Pila 1")
        print("6) Mostrar - Pila 2")
        print("7) Salida")

        op = int(input())

        if op == 1:
            data = input("\nIngrese dato: ")
            tope1 = push(data, tope1, 1)
            print()
        elif op == 2:
            data = input("\nIngrese dato: ")
            tope2 = push(data, tope2, 2)
            print()
        elif op == 3:
            tope1 = pop(tope1, 1)
        elif op == 4:
            tope2 = pop(tope2, 2)
        elif op == 5:
            mostrar(tope1, 1)
        elif op == 6:
            mostrar(tope2, 2)



# ==================== MAIN ===========================
vectorSize = input("¿Que longitud (N) tendrá el vector? ")
v = [None] * int(vectorSize)
tope1 = -1
tope2 = int(vectorSize)

menu()