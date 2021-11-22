#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "classes/player.h"
#include "Memonsters.h"
#include <stack>
#include <queue>


using namespace std;

struct mostro
{
    int id;
    string nombre;
    string descripcion;
    string img;

};


int main() {
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Memonsters");
    sf::Texture texture, textMemostro;
    sf::Sprite image, spPlayer;
    sf::Font font;
    sf::Text nombreTxt, descripcionTxt, encontrar, noEncontrar;
    sf::Sprite spriteMemostro;


    window.setKeyRepeatEnabled(false);
    font.loadFromFile("ARIALBD.TTF");
    nombreTxt.setFont(font);
    nombreTxt.setFont(font);


    if (!texture.loadFromFile("assets/memonsters_mapa.png")) {
        std::cout << "Error al cargar textura, verifique la ruta";
        return EXIT_FAILURE;
    }
    image.setTexture(texture);
    image.setPosition((0), 0);

    window.setFramerateLimit(30);

    // Load a sprite to display
    sf::Texture tx_player;
    if (!tx_player.loadFromFile("assets/player.png"))
        return EXIT_FAILURE;

    Player *player;
    player = new Player(window.getSize().x/2,window.getSize().y/2,tx_player);
 
        // Start the game loop
        while (window.isOpen()) {
            int num=0;
            // Process events
            sf::Event event;
            while (window.pollEvent(event)) {
                // Close window:d exit

                if (event.type == sf::Event::Closed)
                    window.close();

                stack<int> que; //insertar esto afuera del press E
                //Aca uso Pilas <---------
                srand(time(NULL));
                for (int i = 0; i < 10; i++){
                    num = 1 + rand()%100;
                    que.push(num);
                }

                if(event.type==sf::Event::KeyPressed){
                    if(event.key.code==sf::Keyboard::E) {
                        int rng = 0, tc = 0;
                        int calidad = 0, id = 0;
                        string trash = " ", player = " ", bot = " ", nombre = " ", descripcion = " ", imagen = " ";


                        srand(time(NULL));
                        Memonster p;
                        queue<Memonster> pilaMemonster;
                        rng = que.top();
                        que.pop();
                        num = 1 + rand()%100;
                        que.push(num);
                        if (rng > 0 && rng <= 50) {
                            calidad = 1;
                            cout << "\n(" << rng << ") Memonster Comun \n" << endl;

                            ifstream ifsc; //creo un objeto de la libreria ifstream
                            ifsc.open("MemonstersComunes.txt"); //abro el archivo
                            if (ifsc.is_open()) {
                                ifsc >> trash;
                                ifsc >> tc;
                                struct mostro *comun;
                                comun = new mostro[tc];
                                cout << "Tamanio: " << tc << "\n" << endl;

                                for (int i = 0; i < tc; i++) {

                                    ifsc >> trash;
                                    ifsc >> comun[i].id;

                                    ifsc >> trash;
                                    ifsc >> comun[i].nombre;

                                    ifsc >> trash;
                                    ifsc >> comun[i].img;

                                    ifsc >> trash;
                                    ifsc >> comun[i].descripcion;

                                }

                                rng = rand() % tc;
                                cout << "Aparecio... " << comun[rng].nombre << endl;
                                cout << comun[rng].descripcion << "\n" << endl;

                                id = comun[rng].id;
                                nombre = comun[rng].nombre;
                                descripcion = comun[rng].descripcion;
                                imagen = comun[rng].img;
                                cout << comun[rng].img;
                                textMemostro.loadFromFile(comun[rng].img);
                                spriteMemostro.setTexture(textMemostro);
                                spriteMemostro.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                                spriteMemostro.setScale(1.0f,1.0f);

                                encontrar.setString("Encontraste un Memonster!");
                                encontrar.setFont(font);
                                encontrar.setFillColor(sf::Color::Black);
                                encontrar.setPosition(600, 200);
                                encontrar.setCharacterSize(30);

                                nombreTxt.setString(nombre);
                                nombreTxt.setFont(font);
                                nombreTxt.setFillColor(sf::Color::Black);
                                nombreTxt.setPosition(150, 300);
                                nombreTxt.setCharacterSize(30);

                                descripcionTxt.setString(descripcion);
                                descripcionTxt.setFont(font);
                                descripcionTxt.setFillColor(sf::Color::Black);
                                descripcionTxt.setPosition(150, 350);
                                descripcionTxt.setCharacterSize(30);
                            }
                            ifsc.close();

                        } else if (rng > 50 && rng <= 85) {
                            calidad = 2;
                            cout << "\n(" << rng << ") Memonster Raro \n" << endl;

                            ifstream ifsr; //creo un objeto de la libreria ifstream
                            ifsr.open("MemonstersRaros.txt"); //abro el archivo

                            if (ifsr.is_open()) {
                                ifsr >> trash;
                                ifsr >> tc;

                                struct mostro *raro;
                                raro = new mostro[tc];

                                for (int i = 0; i < tc; i++) {

                                    ifsr >> trash;
                                    ifsr >> raro[i].id;

                                    ifsr >> trash;
                                    ifsr >> raro[i].nombre;

                                    ifsr >> trash;
                                    ifsr >> raro[i].img;

                                    ifsr >> trash;
                                    ifsr >> raro[i].descripcion;

                                }

                                rng = rand() % tc;
                                cout << "Aparecio... " << raro[rng].nombre << endl;
                                cout << raro[rng].descripcion << "\n" << endl;

                                id = raro[rng].id;
                                nombre = raro[rng].nombre;
                                descripcion = raro[rng].descripcion;
                                imagen = raro[rng].img;

                                textMemostro.loadFromFile(imagen);
                                spriteMemostro.setTexture(textMemostro);
                                spriteMemostro.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                                spriteMemostro.setScale(1.0f,1.0f);

                                encontrar.setString("Encontraste un Memonster!");
                                encontrar.setFont(font);
                                encontrar.setFillColor(sf::Color::Black);
                                encontrar.setPosition(600, 200);
                                encontrar.setCharacterSize(30);

                                nombreTxt.setString(nombre);
                                nombreTxt.setFont(font);
                                nombreTxt.setFillColor(sf::Color::Black);
                                nombreTxt.setPosition(150, 300);
                                nombreTxt.setCharacterSize(30);

                                descripcionTxt.setString(descripcion);
                                descripcionTxt.setFont(font);
                                descripcionTxt.setFillColor(sf::Color::Black);
                                descripcionTxt.setPosition(150, 350);
                                descripcionTxt.setCharacterSize(30);
                            }
                            ifsr.close();
                        } else if (rng > 85 && rng <= 97) {
                            calidad = 3;
                            cout << "\n(" << rng << ") Memonster Epico \n" << endl;
                            ifstream ifse; //creo un objeto de la libreria ifstream
                            ifse.open("MemonstersEpicos.txt"); //abro el archivo

                            if (ifse.is_open()) {
                                ifse >> trash;
                                ifse >> tc;

                                struct mostro *epico;
                                epico = new mostro[tc];

                                cout << "Tamanio: " << tc << "\n" << endl;

                                for (int i = 0; i < tc; i++) {

                                    ifse >> trash;
                                    ifse >> epico[i].id;

                                    ifse >> trash;
                                    ifse >> epico[i].nombre;

                                    ifse >> trash;
                                    ifse >> epico[i].img;

                                    ifse >> trash;
                                    ifse >> epico[i].descripcion;

                                }

                                rng = rand() % tc;
                                cout << "Aparecio... " << epico[rng].nombre << endl;
                                cout << epico[rng].descripcion << "\n" << endl;

                                id = epico[rng].id;
                                nombre = epico[rng].nombre;
                                descripcion = epico[rng].descripcion;
                                imagen = epico[rng].img;

                                textMemostro.loadFromFile(imagen);
                                spriteMemostro.setTexture(textMemostro);
                                spriteMemostro.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                                spriteMemostro.setScale(1.0f, 1.0f);

                                encontrar.setString("Encontraste un Memonster!");
                                encontrar.setFont(font);
                                encontrar.setFillColor(sf::Color::Black);
                                encontrar.setPosition(600, 200);
                                encontrar.setCharacterSize(30);

                                nombreTxt.setString(nombre);
                                nombreTxt.setFont(font);
                                nombreTxt.setFillColor(sf::Color::Black);
                                nombreTxt.setPosition(150, 300);
                                nombreTxt.setCharacterSize(30);

                                descripcionTxt.setString(descripcion);
                                descripcionTxt.setFont(font);
                                descripcionTxt.setFillColor(sf::Color::Black);
                                descripcionTxt.setPosition(150, 350);
                                descripcionTxt.setCharacterSize(30);
                            }
                            ifse.close();

                        } else if (rng > 97 && rng <= 100) {
                            calidad = 4;
                            cout << "\n(" << rng << ") Memonster Legendario \n" << endl;
                            ifstream ifsl; //creo un objeto de la libreria ifstream
                            ifsl.open("MemonstersLegendarios.txt"); //abro el archivo

                            if (ifsl.is_open()) {
                                ifsl >> trash;
                                ifsl >> tc;

                                struct mostro *legendario;
                                legendario = new mostro[tc];

                                cout << "Tamanio: " << tc << "\n" << endl;

                                for (int i = 0; i < tc; i++) {

                                    ifsl >> trash;
                                    ifsl >> legendario[i].id;

                                    ifsl >> trash;
                                    ifsl >> legendario[i].nombre;

                                    ifsl >> trash;
                                    ifsl >> legendario[i].img;

                                    ifsl >> trash;
                                    ifsl >> legendario[i].descripcion;

                                }

                                rng = rand() % tc;
                                cout << "Aparecio... " << legendario[rng].nombre << endl;
                                cout << legendario[rng].descripcion << "\n" << endl;

                                id = legendario[rng].id;
                                nombre = legendario[rng].nombre;
                                descripcion = legendario[rng].descripcion;
                                imagen = legendario[rng].img;

                                encontrar.setString("Encontraste un Memonster Legendario!!!");
                                encontrar.setFont(font);
                                nombreTxt.setFillColor(sf::Color::Black);
                                nombreTxt.setPosition(80, 80);
                                nombreTxt.setCharacterSize(50);

                                textMemostro.loadFromFile(imagen);
                                spriteMemostro.setTexture(textMemostro);
                                spriteMemostro.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                                spriteMemostro.setScale(1.5f,1.5f);

                                encontrar.setString("Encontraste un Memonster!");
                                encontrar.setFont(font);
                                encontrar.setFillColor(sf::Color::Black);
                                encontrar.setPosition(600, 200);
                                encontrar.setCharacterSize(30);

                                nombreTxt.setString(nombre);
                                nombreTxt.setFont(font);
                                nombreTxt.setFillColor(sf::Color::Black);
                                nombreTxt.setPosition(150, 300);
                                nombreTxt.setCharacterSize(30);

                                descripcionTxt.setString(descripcion);
                                descripcionTxt.setFont(font);
                                descripcionTxt.setFillColor(sf::Color::Black);
                                descripcionTxt.setPosition(150, 350);
                                descripcionTxt.setCharacterSize(30);
                            }
                            ifsl.close();
                        }

						
						
						
						// En este punto se Cargan los memonsters Capturados <---------------------------------------------
						int totalCapturados = 0, code = 0;
						string name = " ", description = " ", rarity = " "; 
						
						
						//Leer el archivo
						ifstream lecap; //creo un objeto de la libreria ifstream
						lecap.open("MemonstersCapturados.txt"); //abro el archivo
						
						if (lecap.is_open()){
							lecap >> trash;
							lecap >> totalCapturados;
							
							for(int i=0; i<totalCapturados;i++){
								
								lecap >> trash;
								lecap >> code;
								p.setCodigo(code);
								
								lecap >> trash;
								lecap >> name;
								p.setNombre(name);
								
								lecap >> trash;
								lecap >> description;
								p.setDescripcion(descripion);
								
								lecap >> trash;
								lecap >> rarity; 
								p.setRareza(rarity);
								
								pilaMemonster.push(p);
								
							}
							
							
							
						}
						lecap.close(); 
						
						
						
						// En este punto se Guardan los memonsters Capturados <---------------------------------------------
						p.setCodigo(id);
						p.setNombre(nombre);
						p.setDescripcion(descripcion);
						if(calidad==1){ 
							p.setRareza("Comun");
						}else if(calidad==2){ 
							p.setRareza("Raro");
						}else if(calidad==3){ 
							p.setRareza("Epico");
						}else if(calidad==4){ 			
							p.setRareza("Legendario");}
						
						pilaMemonster.push(p);
						totalCapturados++;
						
						ofstream ofcap; //creo un objeto de la libreria ofstream
						
						ofcap.open("MemonstersCapturados.txt");
						
						
						ofcap<<"Cantidad_Total: "<<totalCapturados<<"\n"<<endl;
						for(int i=0; i<totalCapturados;i++){
							p=pilaMemonster.front();
							ofcap<<"ID: "<<p.getCodigo()<<"\nNombre: "<<p.getNombre()<<"\nDescripcion: "<<p.getDescripcion()<<"\nRareza: "<<p.getRareza()<<"\n\n";
							cout<<"--------\nCodigo:"<<"\nNombre: "<<p.getNombre()<<"\nDescripcion: "<<p.getDescripcion()<<"\nRareza: "<<p.getRareza()<<"\n--------\n"<<endl;
							pilaMemonster.pop();
						}
						ofcap.close(); 
						
							

                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        player->arriba();
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        player->abajo();
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                        player->izquierda();
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        player->derecha();
                    }
                }






            }
            window.clear();
            window.draw(image);
            window.draw(player->getSprite());
            

            //----- aca van las imagenes del juego
            window.draw(encontrar);
            window.draw(nombreTxt);
            window.draw(descripcionTxt);
            window.draw(spriteMemostro);
            window.display();
        }
        // Update world parameters
        // player.move(3,4);

        // Draw all elements



    return 0;
}


