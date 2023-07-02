#include "bits/stdc++.h"
using namespace std;

#define MAXV 1001000
typedef pair<int, int> pii;

int n, distancia[MAXV];
vector<pii> adj[MAXV];


//O(N.log(N))

void dijkstra(int fonte){
	for(int i=0;i<=n;i++)//Marca como não visitado
		distancia[i]=-1;

	set<pii> fila;
	fila.insert({0,fonte});//Par de distância e vértice

	pii aux;
	while(!fila.empty()){//Enquanto ainda há nós para visitar
		aux=*fila.begin();
		fila.erase(fila.begin());

		int vertice=aux.second;
		int distV=aux.first;

		if(distancia[vertice]!=-1)//Se já foi visitado, passa para o próximo
			continue;

		distancia[vertice]=distV;

		for(auto vizinho: adj[vertice]){
			if(distancia[vizinho.first]!=-1)//Se já foi visitado, não adicionar no set
				continue;
			fila.insert({vizinho.second+distV,vizinho.first});// d[vizinho]=d[vertice]+peso_da_aresta
		}
	}
}