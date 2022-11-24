using System;

namespace GraphHub{

    class Grafo{
        private int vertice = 0;
        private List<Aresta> aresta = new List<Aresta>();

        public Grafo(){
            int size;

            Console.Write("Insira a quantidade de vértices: ");
            this.vertice = int.Parse(Console.ReadLine());
            Console.Write("Insira a quantidade de arestas: ");
            size = int.Parse(Console.ReadLine());
            
            for (int i = 0; i < size; i++){
                int orig = 0, dest = 0, peso = 0;

                Console.Write("Insira o vértice de origem da aresta "+ (i+1) +": ");
                orig = int.Parse(Console.ReadLine());
                Console.Write("Insira o vértice de destino da aresta "+ (i+1) +": ");
                dest = int.Parse(Console.ReadLine());
                Console.Write("Insira o peso da aresta "+ (i+1) +": ");
                peso = int.Parse(Console.ReadLine());

                orig--; dest--;

                this.aresta.Add(new Aresta(orig, dest, peso));
            }
        }

        public void MostrarGrafo(){
            Console.WriteLine("Vértices: ");
            for (int i = 0; i < this.vertice; i++){
                Console.Write($"[{i + 1}] ");
            }
            Console.WriteLine();
            Console.WriteLine("Arestas: " + this.aresta.Count());
            foreach (var edge in this.aresta){
                Console.WriteLine($"[{edge.origem}]- {edge.peso} ->[{edge.destino}]");
            }
        }

        public void InserirVertice(){
            this.vertice ++;
            Console.WriteLine($"Vértice [{this.vertice}] Inserido!");
        }

        public void InserirAresta(){
            int orig = 0, dest = 0, peso = 0;

                Console.Write("Insira o vértice de origem da aresta: ");
                orig = int.Parse(Console.ReadLine());
                Console.Write("Insira o vértice de destino da aresta: ");
                dest = int.Parse(Console.ReadLine());
                Console.Write("Insira o peso da aresta: ");
                peso = int.Parse(Console.ReadLine());

                orig--; dest--;

                this.aresta.Add(new Aresta(orig, dest, peso));
        }

        public void MatrizAdjacencia(){
            int size = this.vertice;
            int[,] matriz = new int[size, size];
            int[,] bin_matriz = new int[size, size];

            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    matriz[i, j] = 0;
                    bin_matriz[i, j] = 0;
                }
            }
            
            foreach (var edge in this.aresta){
                matriz[edge.origem, edge.destino] = edge.peso;
                bin_matriz[edge.origem, edge.destino] = 1;
            }

            Console.WriteLine("Matriz de Adjacência: ");
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    Console.Write($"[{bin_matriz[i,j]}] ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("Matriz de Custos: ");
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    Console.Write($"[{matriz[i,j]}] ");
                }
                Console.WriteLine();
            }
        }

        public void ListaAdjacencia(){
            List<List<int>> vtx = new List<List<int>>();
            for (int i = 0; i < this.vertice; i++){
                vtx.Add(new List<int>());
            }

            foreach (var edge in this.aresta){
                vtx.ElementAt(edge.origem).Add(edge.destino);
            }

            Console.WriteLine("Lista de Adjacências: ");
            for (int i = 0; i < this.vertice; i++){
                Console.Write($"[{i+1}]");
                foreach (var adj in vtx.ElementAt(i)){
                    Console.Write($"-->[{adj+1}]");
                }
                Console.WriteLine();
            }
        }

        private int DfsVisita(int tempo, int[] cor, int[] predecessor,int[] tempo_inicial, int[] tempo_final, int i){
            tempo++;
            tempo_inicial[i] = tempo;
            cor[i] = 1;

            List<Aresta> adjs = new List<Aresta>();
            foreach (var edge in this.aresta){
                if(edge.origem == i){
                    adjs.Add(edge);
                }
            }
            foreach (var edge in adjs){
                if(cor[edge.destino] == 0){
                    predecessor[edge.destino] = edge.origem;
                    tempo = DfsVisita(tempo, cor, predecessor, tempo_inicial, tempo_final, edge.destino);
                }
            }

            cor[i] = 2;
            tempo++;
            tempo_final[i] = tempo;

            return tempo;
        }
        
        public void Dfs(){
            int[] cor = new int[this.vertice];
            int[] predecessor = new int[this.vertice];
            int[] tempo_inicial = new int[this.vertice];
            int[] tempo_final = new int[this.vertice];

            int tempo = 0;

            for (int i = 0; i < this.vertice; i++){
                cor[i] = 0;
                predecessor[i] = -1;
            }

            for (int i = 0; i < this.vertice; i++){
                if(cor[i] == 0){
                    DfsVisita(tempo, cor, predecessor, tempo_inicial, tempo_final, i);
                }
            }

            Console.WriteLine("Depth First Search");
            for (int i = 0; i < this.vertice; i++){
                Console.WriteLine($"Vértice [{i + 1}]: ");
                Console.WriteLine($"\tPredecessor [{predecessor[i] + 1}]");
                Console.WriteLine($"\tTempo Inicial [{tempo_inicial[i]}]");
                Console.WriteLine($"\tTempo Final [{tempo_final[i]}]");
            }
        }

        public void Djikstra(){

        }

        public void OrdenacaoTopologica(){
            int[] entrada = new int[this.vertice];
            List<int> fila = new List<int>();
            List<int> fila_ordenada = new List<int>();

            for (int i = 0; i < this.vertice; i++){
                entrada[i] = 0;
            }

            foreach (var edge in this.aresta){
                entrada[edge.destino]++;
            }

            for (int i = 0; i < this.vertice; i++){
                if(entrada[i] == 0){
                    fila.Add(i);
                    entrada[i] = -1;
                }
            }

            while(fila.Count() > 0){
                int num =  fila.ElementAt(0);

                fila_ordenada.Add(num);
                fila.Remove(num);
                entrada[num] = -1;

                foreach (var edge in this.aresta){
                    if(edge.origem == num){
                        entrada[edge.destino]--;
                    }
                }
                for (int i = 0; i < this.vertice; i++){
                    if(entrada[i] == 0){
                        fila.Add(i);
                        entrada[i] = -1;
                    }
                }
            }

            Console.WriteLine("Ordenação Topológica:");
            foreach (var vtx in fila_ordenada){
                Console.Write($"[{vtx + 1}] ");
            }
            Console.WriteLine();

        }

        public void Kruskal(){
            List<Aresta> kruskal = new List<Aresta>();
            List<List<int>> conj = new List<List<int>>();

            for (int i = 0; i < this.vertice; i++){
                conj.Add(new List<int>());
                conj[i].Add(i);
            }
            List<Aresta> sorted_aresta = this.aresta.OrderBy(e=>e.peso).ToList();

            foreach (var edge in sorted_aresta){
                Console.WriteLine(conj[edge.origem].Contains(edge.destino));
                if(conj[edge.origem].Contains(edge.destino)){

                } else{
                    kruskal.Add(edge);
                    conj[edge.origem].Union(conj[edge.destino]);
                    conj[edge.destino].Clear();
                }
            }
            
            Console.WriteLine("Árvore Geradora Mínima de Kruskal:");
            foreach (var edge in kruskal){
                Console.WriteLine($"[{edge.origem}]-{edge.peso}->[{edge.destino}]");
            }
        }
    }
}