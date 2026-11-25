#include <raylib.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    Image Imagem_original = LoadImage("codigo/assets/imagem_teste.png");

    if (!IsImageValid(Imagem_original)) {
        cerr << "Erro ao carregar imagem.\n";
        return 1;
    }

    Rectangle Recorte1 = {0, 0, 368, 368};
    Rectangle Recorte2 = {368, 0, 368, 368};
    Rectangle Recorte3 = {0, 368, 368, 368};
    Rectangle Recorte4 = {368, 368, 368, 368};

    Image peca1 = ImageFromImage(Imagem_original, Recorte1);
    Image peca2 = ImageFromImage(Imagem_original, Recorte2);
    Image peca3 = ImageFromImage(Imagem_original, Recorte3);
    Image peca4 = ImageFromImage(Imagem_original, Recorte4);

    if (!IsImageValid(peca1) || !IsImageValid(peca2) ||
        !IsImageValid(peca3) || !IsImageValid(peca4)) {

        cerr << "Pecas invalidas.\n";
        return 1;
    }

    vector<Image> pecas;

    pecas.push_back(peca1);
    pecas.push_back(peca2);
    pecas.push_back(peca3);

    // A quarta peça representa o espaço vazio.
    UnloadImage(peca4);
    UnloadImage(Imagem_original);

    cout << "Quantidade de pecas: " << pecas.size() << "\n";

    for (int i = 0; i < pecas.size(); i++) {
        cout << "Peca " << i + 1 << ": "
             << pecas[i].width << " x "
             << pecas[i].height << "\n";
    }

    InitWindow(800, 800, "TestesRachaCuca");
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
            }

            CloseWindow();
            return 1;
        }

        Texturas.push_back(textura);
    }

    // As imagens originais não são mais necessárias.
    for (Image &p : pecas) {
        UnloadImage(p);
    }

    pecas.clear();

    // Exibe as três peças e deixa o quarto espaço vazio.
    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(Texturas[0], 32, 32, WHITE);
        DrawTexture(Texturas[1], 400, 32, WHITE);
        DrawTexture(Texturas[2], 32, 400, WHITE);

        // Representação do espaço vazio.
        DrawRectangle(400, 400, 368, 368, LIGHTGRAY);

        // Divisões do tabuleiro.
        DrawRectangleLines(32, 32, 736, 736, DARKGRAY);
        DrawLine(400, 32, 400, 768, DARKGRAY);
        DrawLine(32, 400, 768, 400, DARKGRAY);

        EndDrawing();
    }

    // Libera as texturas da memória.
    for (Texture2D &textura : Texturas) {
        UnloadTexture(textura);
    }

    CloseWindow();

    return 0;
}