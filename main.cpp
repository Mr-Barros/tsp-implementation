#include <string>

#include "FileDecoder.hpp"
#include "TSPInstance.hpp"

int main(void) {
    using namespace std;

    string filename, repeat;

    do {
        cout << "Nome da instância (ex: a280): ";
        cin >> filename;

        try {
            FileDecoder decoder(filename);
            TSPInstance tsp = decoder.decode_input_file();
        } catch (const std::string& ex) {
            cout << ex << endl;
        }

        cout << "Digite 1 para rodar outra instância, ou 0 para sair: ";
        cin >> repeat;
    } while (repeat != "0");

    cout << "Programa finalizado" << endl;

    return 0;
}