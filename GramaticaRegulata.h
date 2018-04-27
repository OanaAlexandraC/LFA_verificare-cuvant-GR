#ifndef LFA_VERIFICARE_CUVANT_GR_GRAMATICAREGULATA_H
#define LFA_VERIFICARE_CUVANT_GR_GRAMATICAREGULATA_H

class GramaticaRegulata {
    int numarSimboluriNeterminale;
    char *simboluriNeterminale;
    int numarSimboluriTerminale;
    char *simboluriTerminale;
    int numarProductii;
    struct productie {
        char simbolNeterminal1, simbolTerminal, simbolNeterminal2;
    } *reguliDeProductie;
    char simbolCurent;
public:
    explicit GramaticaRegulata(const char *fisier);

    ~GramaticaRegulata();

    void afisare();

    //bool verificare(char *cuvant);
};

#endif
