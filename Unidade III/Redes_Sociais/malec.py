import igraph as ig
import matplotlib.pyplot as plt
import os

'''Criação do Grafo'''
grafo = ig.Graph()
grafo['titulo'] = "Koonfia_Social"
exit = False
fig, ax = plt.subplots(figsize=(15, 15))

'''Adicionar vértices ao Grafo'''


def adicionar_usuario():
    '''Adiciona pessoas sem problema algum,porém o ideal é buscar uma forma de combater a duplicidade de usuários'''
    print("Insira o nome do usuário")
    username = input("> ")
    grafo.add_vertex(name=username)
    print("Usuário: "+username+" adicionado!")


'''Adicionar arestas ao Grafo'''


def adicionar_conexao():
    '''Funciona, porém preciso resolver o loop'''
    aresta1 = int(input("Insira o ponto de partida: "))
    aresta2 = int(input("Insira o ponto de chegada : "))
    grafo.add_edge(aresta1, aresta2)


def mostrar_grafo():
    print("Qual o tipo de visualização você deseja?")
    print("1 - CIRCULAR")
    print("2 - KAMADA KAWAI")
    print("3 - TREE")
    response = int(input("Escolha a opção: > "))

    match response:
        case 1:
            mostrar_grafo_circular()
        case 2:
            mostrar_grafo_kamada_kawai()
        case 3:
            mostrar_grafo_tree()
        case _:
            print("Opção inválida!")


def mostrar_grafo_circular():
    print("VISUALIZAÇÃO DA REDE DE FORMA: CIRCULAR\n\n")
    ig.plot(
        grafo,
        target=ax,
        layout="circle",
        vertex_size=0.1,
        vertex_color="steelblue",
        vertex_frame_color="white",
        vertex_label=grafo.vs["name"])
    plt.show()


def mostrar_grafo_kamada_kawai():
    print("VISUALIZAÇÃO DA REDE DE FORMA: KAMADA KAWAI\n\n")
    ig.plot(
        grafo,
        target=ax,
        layout="kamada_kawai",
        vertex_size=0.1,
        vertex_color="steelblue",
        vertex_frame_color="white",
        vertex_label=grafo.vs["name"])
    plt.show()


def mostrar_grafo_tree():
    print("VISUALIZAÇÃO DA REDE DE FORMA: TREE\n\n")
    ig.plot(
        grafo,
        target=ax,
        layout="tree",
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
    print("=-=-=-REDE KOONFIA-=-=-=")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    print("1 - Adicionar usuário")
    print("2 - Adicionar conexão")
    print("3 - Propriedades da rede")
    print("4 - Visualizar a rede")
    print("5 - Importar grafo")
    print("6 - Sair")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    response = int(input("Escolha a opção: > "))

    match response:
        case 1:
            adicionar_usuario()
        case 2:
            adicionar_conexao()
        case 4:
            mostrar_grafo()
        case 6:
            exit = True
        case _:
            print("Opção inválida!")

    if exit:
        break

    pause_system()
