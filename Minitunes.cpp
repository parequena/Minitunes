/*
    Project: Minitunes
    Author : Pablo Requena (Twitter: @conPdePABLO)
    GitHub : https://github. com/parequena/
    Date   : March 2020
*/

/*
NOTICE:
    - This is an old Programacion 2 (Grado Ing. Informatica, Universidad de Alicante) practice. 
    - It's made within more avanced knowledge than that subject. 
    - If you copy this solution, for sure you gonna get a 0. 
    - DO NOT COPY. LEARN. 

ANUNCIO:
    - Esta es una antigua practica de Programacion 2 (Grado Ing. Informatica, Universidad de Alicante)
    - Esta realizada con conocimientos mas avanzados que esa asignatura. 
    - Si copias esta practica, lo mas seguro que es te suspendan. 
    - NO COPIES. APRENDE. 
*/

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

constexpr auto k_mainMenu{ R"(--------------------------------
----------- MiniTunes ----------
--------------------------------
1- Add song
2- Edit song
3- Delete song
4- Show collection
5- Manage playlist
6- Import iTunes JSON data
7- Export playlist to XSPF
8- Save data
9- Load data
0- Play playlist
q- Quit
Option:)" };
constexpr auto k_mainMenuError{ "Error: Unknown option" };
constexpr auto k_songSeparator{ " | " };
// ---------------------------------------------
constexpr auto k_songDemandTitle { "Title:" };
constexpr auto k_songDemandArtist{ "Artist:" };
constexpr auto k_songDemandAlbum { "Album:" };
constexpr auto k_songDemandGenre { "Genre:" };
constexpr auto k_songDemandUrl   { "Url:" };

struct Song_t
{
	// Id. 
    uint8_t m_id{ 0 };
	
	// Title. 
    std::string m_title{};

	// Artist. 
    std::string m_artist{};

	// Album
    std::string m_album{};

	// Genre. 
    std::string m_genre{};

	// Url. 
    std::string m_url{};

	inline friend std::ostream& operator<<(std::ostream& os, const Song_t& s)
	{
        os  << s. m_id << k_songSeparator << s. m_title << k_songSeparator
            << s. m_artist << k_songSeparator << s. m_album << k_songSeparator
            << s. m_genre << "\n";

        return os;
	}

	inline friend bool operator==(const Song_t& lhs, const Song_t& rhs) noexcept
	{
        return lhs.m_title == rhs.m_title
            && lhs.m_artist == rhs.m_artist;
	}
};


struct Collection_t
{
	// Next song id.
    uint8_t m_id{ 1 };
	
	// Song collection.
    std::vector<Song_t> m_songs{};
};

/////////////////////////////////////////////////////////
// First subject (/pdf/prog2p1).
/////////////////////////////////////////////////////////

// Funcion que busca la cancion que se le pasa por parametro en la coleccion. Si ya existe una con el mismo tıtulo y autor, debe devolver
// true, y en caso contrario false
bool isSongInCollection(const Collection_t& collection, const Song_t& song) noexcept
{
	const auto& cs = collection.m_songs;
	
    return std::find(cs.begin(), cs.end(), song) != cs.end();
}

// Funcion para añadir una cancion a la coleccion. Si ya existe(para
// ello se debe llamar a la funcion anterior), debe devolver false y no
// añadirla. En caso contrario la cancion debe añadirse a la coleccion
// con el identificador id = idNextSong, e incrementar idNextSong para
// la siguiente cancion que vaya a insertarse en la coleccion. 
// Para añadir un elemento e a un vector v, puedes usar : v. push_back(e); . 
// Esta funcion debe llamar a demandSong para pedir los datos de la cancion. 
bool addSong(Collection_t& collection) noexcept
{
    std::cout << "Add\n";
    return false;
}

// Funcion que pide por teclado todos los datos de la cancion y la devuelve. 
Song_t demandSong() noexcept
{
    Song_t song;
    
	
	
    return {};
}

// Funcion para imprimir una cancion con su identificador, tıtulo, autor,
// album y genero. Por ejemplo :
// 35 | Here Comes the Sun | The Beatles | Abbey Road | Rock
void printSong(const Song_t& song) noexcept
{
    std::cout << song << "\n";
}

// Funcion para buscar un identificador de cancion(id) en la coleccion. 
// Devuelve la posicion del vector de canciones(songs) donde se ha encontrado, o - 1 si la cancion no esta en la coleccion. 
int findIdSong(const Collection_t& collection, const int id) noexcept
{
    return -1;
}

// Esta funcion mostrara por pantalla las canciones que cumplan el criterio de busqueda solicitado al usuario. Si la busqueda no produce
// ningun resultado, debe devolver false, y en caso contrario true
bool showCollection(Collection_t& collection) noexcept
{
    std::cout << "Show\n";
    return false;
}

// Funcion que muestra las canciones mediante showCollection. Si esta
// devuelve true, a continuacion pedira el numero de cancion a editar,
// que se buscara en la coleccion mediante findIdSong. Si devuelve false
// no se hara nada. Tras localizar la cancion se le pedira al usuario que
// indique el campo a editar y se modificara esta cancion en la coleccion. 
bool editSong(Collection_t& collection) noexcept
{
    std::cout << "Edit\n";
    return false;
}

// Funcion que muestra las canciones mediante showCollection. Si esta
// devuelve true, a continuacion pedira el numero de cancion a borrar,
// que se buscara en la coleccion mediante findIdSong. Si devuelve false
// no se hara nada. Tras localizar la cancion se le pedira al usuario un
// mensaje de confirmacion de borrado, y si su respuesta es afirmativa se
// eliminara la cancion de la coleccion. 
bool deleteSong(Collection_t& collection) noexcept
{
    std::cout << "Delete\n";
    return false;
}

/////////////////////////////////////////////////////////
// Second subject (/pdf/prog2p2).
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// Third subject (/pdf/prog2p3).
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
/// Aux functions.
/////////////////////////////////////////////////////////
struct MenuOptions_t
{
    char m_response;
    bool (*pf)(Collection_t&) noexcept;
};

MenuOptions_t mainMenu[] =
{
    {'1', &addSong},
    {'2', &editSong},
    {'3', &deleteSong},
    {'4', &showCollection},
    {0,nullptr}
};

int main()
{
    char userResp{};
    MenuOptions_t* menu{ nullptr };
    Collection_t collection{};
    bool printError{ true }, execResult{false};
	
    do
    {
        std::cout << k_mainMenu << "\n";
        std::cin >> userResp;
        menu = mainMenu;
        printError = execResult = true;

    	while(menu->m_response != 0)
    	{
    		if(userResp == menu->m_response)
    		{
                printError = false;
                execResult = menu->pf(collection);
    		}
    		
            ++menu;
    	}

        if(printError) std::cerr << k_mainMenuError << "\n";
    	
    } while (userResp != 'q');
	
    return 0;
}