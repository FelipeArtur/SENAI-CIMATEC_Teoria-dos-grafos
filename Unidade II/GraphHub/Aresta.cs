using System;

namespace GraphHub{

    class Aresta{
        public int origem;
        public int destino;
        public int peso;

        public Aresta(int orig, int dest, int peso){
            this.origem = orig;
            this.destino = dest;
            this.peso = peso;
        }

    }
    
}
