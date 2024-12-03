#ifndef DISPLAY_H
#define DISPLAY
class Display
{
private:
    int Menu;

public:
    Display();
    void exibiMenu(int);
    void exibirPeso(float);
    void exibirMensagem(char[]);
    void navegarMenu();
};

#endif