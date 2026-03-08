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
            Graph g = tsp.build_graph();
            cout << "Tamanho do caminho canônico: " << g.canonical_tour_length() << endl;
            
            Solution sol;
            vector<int> tsp_tour = sol.find_tsp_tour(g);

            cout << "Caminho TSP encontrado:" << endl;
            for (int i = 0; i < tsp_tour.size(); i++) {
                cout << tsp_tour[i] + 1 << " \n"[i == tsp_tour.size() - 1];
            }

        } catch (const std::string& ex) {
            cout << ex << endl;
        }

        cout << "Digite 1 para rodar outra instância, ou 0 para sair: ";
        cin >> repeat;
    } while (repeat != "0");

    cout << "Programa finalizado" << endl;

    return 0;
}