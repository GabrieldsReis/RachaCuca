
#include <raylib.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


bool Adjacentes(int indiceA, int indiceB, int N){
int linhaA = indiceA / N;//pos x 
int colunaA = indiceA % N; //pos y

int linhaB = indiceB / N;
int colunaB = indiceB % N;

bool horizontal = linhaA == linhaB &&
                  (colunaA == colunaB - 1 || colunaA == colunaB + 1);

bool vertical = colunaA == colunaB &&
                (linhaA == linhaB - 1 || linhaA == linhaB + 1);

                return horizontal || vertical;

}


int procura_i(const vector<int>& tabuleiro,int N){
    for(int i=0;i<N*N;i++){
    if(tabuleiro[i]==-1){
        return i;
    }
    
}return -1;
}


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
            }// o ultimo quadrado

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

    vector<int> tabuleiro(N*N); //preciso criar a logica da mudanca de posicoes
//o usarei como indice para o desenho
for(int i=0;i<(N*N-1);i++){
 tabuleiro[i]= i;
}
tabuleiro[N*N-1] = -1;

    float tamanhoCedula = ((float)tamanhoJanela - 2 * 32) / N;

vector<int>VizinhosValidos;
srand(time(nullptr));
for(int j=0;j<100;j++){
VizinhosValidos.clear();

int indiceVazio = procura_i(tabuleiro, N); //aonde esta a posicao vazio

for(int i=0;i<N*N;i++){
    if(Adjacentes(i,indiceVazio,N)){
        VizinhosValidos.push_back(i);
    }
    
}
if (VizinhosValidos.empty()) {
    break;
}

int sorteio = rand() % VizinhosValidos.size();
int indiceVizinho = VizinhosValidos[sorteio];
swap(tabuleiro[indiceVazio],tabuleiro[indiceVizinho]);
}




    while (!WindowShouldClose()) {
       
        
        

if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
Vector2 posicao = GetMousePosition();


    if(!(posicao.x >= 32 &&
posicao.x < 32 + N * tamanhoCedula &&
posicao.y >= 32 &&
posicao.y < 32 + N * tamanhoCedula)
    ){
        continue;
    }

int coluna = (posicao.x-32)/tamanhoCedula;
int linha = (posicao.y-32)/tamanhoCedula;
int indice = linha*N+coluna; //aonde foi o click

int indiceVazio = procura_i(tabuleiro, N); //aonde esta a posicao vazio


cout << "Linha: " << linha
     << "\nColuna: " << coluna
     << "\nIndice: " << indice << "\n"
     << "\nIndice Vazio: " << indiceVazio;



if(indiceVazio!= -1){
bool movimentoValido = Adjacentes(indice, indiceVazio, N);


if (movimentoValido) {
    swap(tabuleiro[indice], tabuleiro[indiceVazio]);
}




}}



        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < linhas; i++) {

            for (int j = 0; j < colunas; j++) {

                // 1. Calcula a posição da célula na janela
                float X = 32 + j * tamanhoCedula;
                float Y = 32 + i * tamanhoCedula;

                // 2. Calcula a posição da peça no vetor
                int indice = i * N + j;
                int idPeca = tabuleiro[indice];
                // 3. Define onde a peça será desenhada
                Rectangle destino = {
                    X, Y,
                    tamanhoCedula,
                    tamanhoCedula
                };

                // 4. Verifica se é a última célula (espaço vazio)
                if (idPeca==-1) {

                    DrawRectangleRec(destino, LIGHTGRAY);
                    DrawRectangleLinesEx(destino,1.0f,GRAY);


                } else {

                    // 5. Define qual parte da textura será utilizada
                    Rectangle origem = {
                        0, 0,
                        (float)Texturas[idPeca].width,
                        (float)Texturas[idPeca].height
                    };

                    Vector2 pontoOrigem = {0, 0};

                    // 6. Desenha a peça
                    DrawTexturePro(
                        Texturas[idPeca],
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
