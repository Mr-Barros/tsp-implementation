#include <string>

#include "FileDecoder.hpp"
#include "TSPInstance.hpp"
#include "Solution.hpp"

int main(void) {
    using namespace std;

    string filename, repeat;

    do {
        cout << "Nome da instância (ex: a280): ";
        cin >> filename;

        try {
            FileDecoder decoder(filename);
            TSPInstance tsp = decoder.decode_input_file();
            Graph tsp_graph = tsp.build_graph();
            
            Solution sol(tsp_graph);
            vector<int> tsp_tour = sol.find_tsp_tour();

            cout << "Caminho TSP encontrado:" << endl;
            for (int i = 0; i < tsp_tour.size(); i++) {
                cout << tsp_tour[i] + 1 << " \n"[i == tsp_tour.size() - 1];
            }
            
            int tour_cost = sol.tsp_tour_cost(tsp_tour);
            cout << "Custo do caminho TSP: " << tour_cost << endl;

            int canonical_cost = tsp_graph.canonical_tour_length();
            cout << "Custo do caminho canônico: " << canonical_cost << endl;
        } catch (const std::string& ex) {
            cout << ex << endl;
        }

        cout << "Digite 1 para rodar outra instância, ou 0 para sair: ";
        cin >> repeat;
    } while (repeat != "0");

    cout << "Programa finalizado" << endl;

    return 0;
}