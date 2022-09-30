# Käytetyt tietorakenteet:

Alueet ja paikat päätettiin tallettaa structeiksi, sillä niiden sijoittaminen hakurakenteiden arvoiksi tekee arvojen etsimisestä nopeaa.  
struct Place {  
    Name const name;  
    PlaceType type;  
    Coord xy;  
    };  

Ala- ja yläalueet tallennetaan ID:nä, mutta tämän voisi myös toteuttaa osoittimena toiseen alueeseen. Koodauksen helppouden takia tämä toteutettiin vain puhtaana ID:nä, sillä ID:llä hakeminen unordereded mapista on vakioaikainen toiminto, eli yhtä nopea kuin osoittimen arvon hakeminen.
struct Area {  
    Name const name;  
    std::vector<Coord> coords;  
    std::unordered_set<AreaID> subareas = {};  
    AreaID parent = -1;  
};


Structit on tallennettu seuraaviin hakurakenteisiin, mitä käytetään funktioissa, joissa haetaan tietoa ID:n perusteella. Halutun ID:n tieto saadaan täten vakioaikaisesti.
std::unordered_map<PlaceID, Place> places_;  
std::unordered_map<AreaID, Area> areas_;  

Pelkät ID:t tallennetaan myös vektoreihin, koska vektorin perään lisääminen on vakioaikaista, mutta muista tietorakenteista iteratiivisesti vektorin tekeminen olisi lineaarista. Näitä voidaan käyttää suoraan palautusarvoina kaikki ID:t kysyvissä funktioissa. Vaikka poistaminen onkin hitaampaa, ei se haittaa sillä poistaminen on harvoin pyydetty funktio.
std::vector<PlaceID> place_ids;  
std::vector<AreaID> area_ids;  

Toisin päin olevia hakurakenteita käytetään arvojen etsimiseen nimellä, koordinaatilla tai paikan tyypillä. Koska kaikkia arvoja voi olla duplikaatteja, tulee näiden olla multimappeja. Nimet ja koordinaatit pidetään järjestyksessä, koska tälloin voidaan lineaarisella kompleksisuudella luoda vektori järjestystä vaativien funktioiden paluuarvoksi. Tyyppien tapauksessa riittää järjestämätön, sillä niitä ei tarvitse palauttaa ikinä missään järjestyksessä. 

coord_map käyttää ennalta määriteltyä < operaattoria pitämään koordinaatit etäisyyden mukaan järjestyksessä. Täten tietorakenteeseen lisääminen on hieman hitaampaa (log n), mutta halutut arvot saadaan haettua huomattavasti nopeammin, eikä tietorakenteita tarvitse järjestää ikinä.
std::multimap<Name, PlaceID> name_map;  
std::multimap<Coord, PlaceID> coord_map;  
std::unordered_multimap<PlaceType, PlaceID> type_map;  

# Käytetyt ratkaisut funktioissa

Ohjelmassa pyrittiin välttämään järjestämisalgoritmeja täysin, sillä niiden kompleksisuus on todella huono. Tämän sijaan käytettiin tiedon tallentamista rinnakkaisiin tietorakenteisiin, joita voidaan manipuloida tehokkaammin. Tämä tuottaa lisää kompleksisuutta tiedon muokkaamisessa, mitä voitaisiin vähentää viitteitä käyttämällä, mutta tällöin joudutaan ratkomaan ongelmia osoittimien invalidoitumisen kanssa. Tiedon hakeminen taas on huomattavasti nopeampaa. Tästä syystä valittiin ratkaisu tallentaa toisteista dataa, sillä tietorakenteiden määrä ei ole vielä liian suuri, etteikö niitä voisi kaikkia manuaalisesti hallita.  

Tietojen järjestämisen sijaan valittiin ratkaisuksi säilyttää tietoja hakurakenteissa, jotka pitävät tiedot automaattisesti järjestyksessä, mutta tällöin lisääminen on hieman hitaampaa. Testien perusteella tämä todettiin nopeammaksi kuin tietorakenteiden järjestäminen tarvittaessa.  
Paikkojen hakeminen tai muokkaaminen nimen tai tyypin tai koordinaattien perusteella saatiin myös täten tiputettua lineaariseksi identtisten arvojen määrän koon suhteen.  

Paikkojen sijainnin vertaaminen valittuun paikkaan toteutettiin Dist-structien avulla, jolloin niille voidaan määrittää oma vertailufunktio, eikä järjestämistä jälleen enää tarvitse tehdä. Alueiden alialueiden tutkiminen tapahtuu rekursiivisillä funktioilla. Yhteisen yläalueen etsiminen tapahtuu melko monimutkaisella funktiolla, mutta näin päästään O(h) tehokkuuteen. Tämä funktio olisi internetin lähteiden mukaan mahdollista toteuttaa vakioaikaisena, mutta sen toteutus näytti sen verran hankalalta, että en sitä lähtenyt toteuttamaan.  

Työn ratkaisuissa siis pyrittiin vakioaikaisuuteen, mutta tieorakenteisiin lisäämisen kompleksisuutta lisättiin hieman, sillä täten säästettiin useassa funktiossa aikaa jättämällä tarve järjestämiselle pois. Joissain funktioissa ei ollut vaihtoehtoa päästä lineaarista kompleksisuutta nopeammaksi, sillä funktioiden paluuarvoina oli vektoreita, jotka pitää muodostaa muista tietorakenteista.

