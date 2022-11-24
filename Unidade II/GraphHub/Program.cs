using System;

namespace GraphHub{
    class Program{
        static void Main(string[] args){
            Console.Clear();
            Grafo graph = new Grafo();
            Console.Clear();

            graph.Kruskal();
        }
    }
}