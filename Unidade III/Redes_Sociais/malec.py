import igraph as ig
import matplotlib.pyplot as plt
import os

grafo = ig.Graph()
grafo['titulo'] = "Koonfia_Social"
exit = False
fig, ax = plt.subplots(figsize=(15, 15))


def adicionar_usuario():
    print("Insira o nome do usuário")
    username = input("> ")
    grafo.add_vertex(name=username)
    print("Usuário "+username+" adicionado!")


def adicionar_conexao():
    edges = [(0, 1), (0, 2), (0, 3), (0, 4), (1, 2), (1, 3), (1, 4), (3, 4)]
    grafo.add_edges(edges)
    """""
    print("Quantas conexões você quer fazer?")
    num_conexoes = input("> ")
    while (num_conexoes > 0):
        grafo.add_edge()
        num_conexoes = num_conexoes-1
        print("Deu bom")
    """


def mostrar_grafo():
    print("VISUALIZAÇÃO DA REDE EM ...\n\n")
    ig.plot(
        grafo,
        target=ax,
        layout="circle",
        vertex_size=0.1,
        vertex_color="steelblue",
        vertex_frame_color="white",
        vertex_label=grafo.vs["name"])
    plt.show()


def clear_system():
    os.system('cls' if os.name == 'nt' else 'clear')


def pause_system():
    pause = input("Pressione ENTER para continuar!")


while True:
    clear_system()
    print("REDE SOCIAL")
    print("1 - Adicionar usuário")
    print("2 - Adicionar conexão")
    print("3 - Propriedades da rede")
    print("4 - Visualizar")
    print("5 - Visualizar")
    print("6 - Visualizar")
    print("7 - Sair")
    response = int(input("Escolha a opção: > "))

    match response:
        case 1:
            adicionar_usuario()
        case 2:
            adicionar_conexao()
        case 4:
            mostrar_grafo()
        case 7:
            exit = True
        case _:
            print("Opção inválida!")

    if exit:
        break

    pause_system()
