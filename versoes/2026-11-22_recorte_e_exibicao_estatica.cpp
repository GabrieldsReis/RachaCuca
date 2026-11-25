
#include <raylib.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    Image Imagem_original = LoadImage("codigo/assets/imagem_teste.png");

    if (!IsImageValid(Imagem_original)) {
        cout << "Erro ao carregar imagem.\n";
        return 1;
    }

    int N;
    cin >> N;

    if (N < 2 || N > 6) {
        cout << "O programa apenas aceita dimensoes de 2 á 6";
        return 1;
    }

    vector<Image> pecas;

    int Largura = Imagem_original.width;
    int Altura = Imagem_original.height;

    int linhas = N;
    int colunas = N;

    for (int i = 0; i < linhas; i++) { //uniformizando o calculo para diferentes N

        for (int j = 0; j < colunas; j++) {

            int X = j * Largura / N;
            int Y = i * Altura / N;

            int XFinal = (j + 1) * Largura / N;
            int YFinal = (i + 1) * Altura / N;

            int larguraRecorte = XFinal - X;
            int alturaRecorte = YFinal - Y;

            if (i == linhas - 1 && j == colunas - 1) {
                continue;
            }

            Rectangle Recorte = {
                (float)X,
                (float)Y,
                (float)larguraRecorte,
                (float)alturaRecorte
            };

            Image peca = ImageFromImage(Imagem_original, Recorte);

            if (!IsImageValid(peca)) {

                cout << "Pecas invalidas.\n";
                return 1;
            }

            pecas.push_back(peca);
        }
    }

    UnloadImage(Imagem_original);

    cout << "Quantidade de pecas: " << pecas.size() << "\n";

    for (int i = 0; i < pecas.size(); i++) {

        cout << "Peca " << i + 1 << ": "
             << pecas[i].width << " x "
             << pecas[i].height << "\n";
    }

    int tamanhoJanela = 800;

    InitWindow(tamanhoJanela, tamanhoJanela, "TestesRachaCuca");
    SetTargetFPS(60);

    vector<Texture2D> Texturas;

    // Converte cada imagem do vetor em uma textura.
    for (int i = 0; i < pecas.size(); i++) {

        Texture2D textura = LoadTextureFromImage(pecas[i]);

        if (!IsTextureValid(textura)) {

            cerr << "Erro ao criar textura.\n";

            for (Texture2D &t : Texturas) {
                UnloadTexture(t);
            }

            for (Image &p : pecas) {
                UnloadImage(p);
            } //caso de erro no meio ou final remove todas as outras

            CloseWindow();
            return 1;
        }

        Texturas.push_back(textura); //caso nao de erro
    }

    // As imagens originais não são mais necessárias.
    for (Image &p : pecas) {
        UnloadImage(p);
    } //eh parecido com o foreach

    pecas.clear();

    // Exibe as três peças e deixa o quarto espaço vazio.
    float tamanhoCedula = ((float)tamanhoJanela - 2 * 32) / N;

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < linhas; i++) {

            for (int j = 0; j < colunas; j++) {

                // 1. Calcula a posição da célula na janela
                float X = 32 + j * tamanhoCedula;
                float Y = 32 + i * tamanhoCedula;

                // 2. Calcula a posição da peça no vetor
                int indice = i * N + j;

                // 3. Define onde a peça será desenhada
                Rectangle destino = {
                    X, Y,
                    tamanhoCedula,
                    tamanhoCedula
                };

                // 4. Verifica se é a última célula (espaço vazio)
                if (i == linhas - 1 && j == colunas - 1) {

                    DrawRectangleRec(destino, LIGHTGRAY);
                    DrawRectangleLinesEx(destino,1.0f,GRAY);


                } else {

                    // 5. Define qual parte da textura será utilizada
                    Rectangle origem = {
                        0, 0,
                        (float)Texturas[indice].width,
                        (float)Texturas[indice].height
                    };

                    Vector2 pontoOrigem = {0, 0};

                    // 6. Desenha a peça
                    DrawTexturePro(
                        Texturas[indice],
                        origem,
                        destino,
                        pontoOrigem,
                        0.0f,
                        WHITE
                    );

                    DrawRectangleLinesEx(destino,1.0f,GRAY);
                }
            }
        }

            EndDrawing();

    }
    for (Texture2D &textura : Texturas) {
        UnloadTexture(textura);
    }


        CloseWindow();

    return 0;
}
