# Käytetyt tietorakenteet:

Työssä pyrittiin tekemään hyvin pitkälle osoittimiin ja viitteisiin perustuva ratkaisu.
Tiet tallennettiin omaksi structikseen, joka sisälsi pituuden, ID:n ja reitin koordinaatit. Risteykset tallennettiin myöskin omaksi structikseen, joka sisälsi risteyksen koordinaatit, ja siitä lähtevien teiden koordinaatit ja osoittimen loppupäässä olevaan risteykseen. Tällä osoittimella poistettiin tarve etsiä osoitin koordinaatilla funktioita tehdessä.

Risteykseen tallennetaan myös tiedot previous, cameFrom, minDist ja estimate. Näitä käytetään A* algoritmissa kun etsitään lyhyin reitti kahden pisteen välillä.

Osoittimet risteyksiin tallennetaan unordered_mappiin käyttäen avaimena koordinaattia. Tiet tallennetaan unordered mappiin käyttäen WayID:tä avaimena. Näiden avulla säilötään tiedot, sekä niitä käytetään koordinaateilla ja ID:llä teiden ja risteysten etsimiseen, esimerkiksi olemassaolon tai lähtöpisteiden tarkistuksessa.

# Käytetyt ratkaisut funktioissa

Funktioissa pyrittiin käyttämään osoittimia ja viitteitä tietorakenteista etsimisen sijaan. Reittien haun tapauksessa lähtö ja alkupisteiden risteykset voidaan hakea vakioaikaisena tietorakenteesta, jonka jälkeen näistä lähteviä teitä voidaan viitteiden avulla kulkea.

Add_way lisää uuden tien rakenteeseen, mutta koska haluttiin kaikkien risteyksistä lähtevien teiden olevan ns. risteyksestä ulospäin, lisätään tie koordinaatit käännettynä loppuristeykseen. Dataa on tällöin tuplana, mutta tämä helpottaa algoritmien kirjoitusta huomattavasti, kun tiedetään aina suoraan mihin risteyksiin päästään minkäkin väylän kautta. Toisaalta olisi todennäköisesti riittänyt, jos olisi tallentanut reitit ilman kääntämistä, sillä loppupiste tallennettiin kuitenkin rakenteeseen. Tätä en kuitenkaan jaksanut alkaa muuttaa enää työn ollessa muuten valmis. Jos tien jommassa kummassa päässä ei ole risteystä, siihen pisteeseen luodaan uusi sellainen ja lisätään uusi tie tähän risteykseen.

Route_any tekee leveyteen ensin haun tietorakenteeseen FIFO jonon avulla ja lopettaa suorituksen heti kun loppupiste on löydetty. Leveyteen ensin valittiin sen toteutuksen helppouden takia, sekä se on melko tehokas näissä tilanteissa. Syvyyteen ensin haku olisi myös toiminut. Algoritmissa käydään risteyksiä läpi ja muutetaan niiden sisäisiä arvoja ja lopuksi käydään iteratiivisesti lopusta alkuun reitti läpi, jonka jälkeen se käännetään ympäri palautettavaan muotoon. Tämä ratkaisu palauttaa myös WayID:t, vaikka niitä ei vaadittu. Funktion lopussa pitää iteroida kaikki risteykset läpi ja asettaa niiden arvot jälleen nollaksi.

Lyhyimmän reitin haku toteuttaa A* algoritmin min heap priority queue rakenteella, jossa heuristinen veikkaus on suora etäisyys käsiteltävästä risteyksestä loppupisteeseen. Tässäkin algoritmissa käydään tietorakennetta läpi algoritmin mallin ja muutetaan risteysten sisäisiä arvoja kunnes löydetään loppupiste, minkä jälkeen kuljetusta reitistä muodostetaan palautettava vector. A* ylläpitää lyhyintä reittiä joka risteykseen, joten se voidaan lopettaa heti maalisolmun löydyttyä. Lopussa jälleen alustetaan arvot nollaksi. A* priority queuella valittiin tähän algoritmiksi koska se on yksi tehokkaimmista kurssilla käydyistä tähän tarkoitukseen soveltuvista algoritmeistä, sekä se on helppo toteuttaa käytetyllä tietorakenteella.

Remove_ways poistaa annetun tien kaikista risteyksistä joissa se on, sekä poistaa risteyksen jos siitä ei enää lähde yhtäkään tietä. Teiden tuplana tallentaminen kostautuu tässä hieman suuremmalla kompleksisuudella, koska risteyksissä on erilaiset tiet tallennettuna ja täten pitää etsiä mikä tie vastaa alkuperäistä tietä. Tähän ei juuri tehokkaampia keinoja keksitty, teiden tallentaminen risteysten sisällä esimerkiksi hakurakenteeseen olisi voinut olla keino nopeuttaa oikean tien poistamista, mutta tämä olisi lisännyt koodin kirjoittamisen monimutkaisuutta omasta mielestä ikävästi. Yhdestä risteyksestä lähtevien teiden määrän voi olettaa sen verran pieneksi, että huonompi tehokkuus ei tässä haittaa.

Muut funktiot ovat vain tietorakenteesta iteratiivisesti palautukseen kelpaavien rakenteiden luomista.


