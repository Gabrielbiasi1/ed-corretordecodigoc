numero = int(input("Digite um número para ver a tabuada: "))

# Exibe a tabuada para o número inserido
print(f"Tabuada do {numero}:")

for i in range(1, 11):
    print(f"{numero} x {i} = {numero * i}")