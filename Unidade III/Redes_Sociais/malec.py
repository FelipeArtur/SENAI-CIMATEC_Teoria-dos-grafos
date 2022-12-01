import igraph as ig
import matplotlib.pyplot as plt
import os

# Criação do Grafo
grafo = ig.Graph()
grafo = ig.read("Grafo.net")
grafo['titulo'] = "Koonfia_Social"
exit = False
fig, ax = plt.subplots(figsize=(15, 15))

# Adicionar vértices ao Grafo
def adicionar_usuario():
    # Adiciona pessoas sem problema algum,porém o ideal é buscar uma forma de combater a duplicidade de usuários
    clear_system()
    print("=-=-=-REDE KOONFIA-=-=-=")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    print("Insira o nome do usuário")
    username = input("> ")
    grafo.add_vertex(name=username)
    print("Usuário "+ username +" adicionado!")

# Adicionar arestas ao Grafo
def adicionar_conexao():
    clear_system()
    print("=-=-=-REDE KOONFIA-=-=-=")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    count = 0
    for vtx in grafo.vs:
        print(count, ' - ', vtx["name"])
        count = count + 1
    vertice_orig = int(input("Insira o usuário de origem: >"))
    vertice_dest = int(input("Insira o usuário de destino: >"))
    peso = int(input("Insira o peso da conexão: >"))
    grafo.add_edge( vertice_orig, vertice_dest, weight=peso)
    print("Conexão "+ grafo.vs[vertice_orig]["name"] + " - " + grafo.vs[vertice_dest]["name"] +" adicionado!")

# Propriedade da rede
def propriedades_rede():
    clear_system()
    qnt_vertices = len(grafo.vs)
    qnt_arestas = len(grafo.es)
    densidade = (2*qnt_arestas)/((qnt_arestas - 1)*qnt_arestas)

    print("=-=-=-REDE KOONFIA-=-=-=")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    print("Ordem: ", qnt_vertices) # quantidade de vertices
    print("Tamanho: ", qnt_arestas) # quantidade de arestas
    print("Densidade: ", densidade) # razão entre o número atual de arestas com o número máximo de arestas (2n/(n-1)*n)
    print("Grau: ") # quantidade de arestas de um vértice
    for vtx in grafo.vs:
        print(vtx["name"], ": ", len(vtx.all_edges()))

# Mostrar grafo
def mostrar_grafo():
    clear_system()
    print("=-=-=-REDE KOONFIA-=-=-=")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    print("1 - Circular")
    print("2 - Kamada-Kawai")
    print("3 - Árvore")
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
    ig.plot( grafo, target=ax, layout="circle", vertex_size=0.1, vertex_color="red", vertex_frame_color="white", vertex_label=grafo.vs["name"], edge_label=grafo.es["weight"])
    plt.show()


def mostrar_grafo_kamada_kawai():
    print("VISUALIZAÇÃO DA REDE DE FORMA: KAMADA KAWAI\n\n")
    ig.plot( grafo, target=ax, layout="kamada_kawai", vertex_size=0.1, vertex_color="red", vertex_frame_color="white", vertex_label=grafo.vs["name"], edge_label=grafo.es["weight"])
    plt.show()


def mostrar_grafo_tree():
    print("VISUALIZAÇÃO DA REDE DE FORMA: TREE\n\n")
    ig.plot( grafo, target=ax, layout="tree", vertex_size=0.1, vertex_color="red", vertex_frame_color="white", vertex_label=grafo.vs["name"], edge_label=grafo.es["weight"])
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
    print("5 - Sair")
    print("=-=-=-=-=-=-=-=-=-=-=-=-")
    response = int(input("Escolha a opção: > "))

    match response:
        case 1:
            adicionar_usuario()
        case 2:
            adicionar_conexao()
        case 3:
            propriedades_rede()
        case 4:
            mostrar_grafo()
        case 5:
            exit = True
        case _:
            print("Opção inválida!")

    if exit:
        clear_system()
        break

    pause_system()
