



void computeHisto(histogram_t h, list_t l) {
    int i = 0;
    int j = 0;
    cell_t * cour = l.key;

    for (i=0; i < HISTOSIZE ; ++i)
        h[i] = 0.0;

    while (cour) {
        ++h[cour->value];
        cour = cour->nk;
        ++j;
    }
} 

void displayHisto(histogram_t h) {
    int i = 0;
    
    for (i=0; i < HISTOSIZE ; ++i)
        printf("[%2d] : %3d\n", i, h[i] );
}

int maxHisto(histogram_t h) {
    int i, max = h[0];
    
    for(i=1; i< HISTOSIZE; ++i)
        if (h[i]>max) max=h[i];
    
    return max;
}

float meanHisto(histogram_t h) {
    float som =0.;
    int   tot = 0, i;
    
    for (i=0; i< HISTOSIZE; ++i) {
        som  = h[i] * i;
        tot += h[i];
    }
    LOG(("MEAN %f / %d\n", som, tot));
    
    return som/(float)tot;
}

int countHisto(histogram_t h) {
    int   tot = 0, i;
    for (i=0; i< HISTOSIZE; ++i) {
        tot += h[i];
    }
    LOG(("TOT %d\n", tot));
  
    return tot;
}

void displayGraphicalHisto(gdata_t g, histogram_t h) {                          
    char          chaine[255];
    int maxx = 600;
    int maxy = 400;
    int i;   
    int j = maxHisto(h);

    XClearWindow(g.dpy, g.win);

    for(i=0; i<HISTOSIZE; ++i) {
        XDrawLine(g.dpy,g.win,g.gcontext,(int)(maxx/22.0*(i+1)), maxy-(int)(h[i]/(float)j*300.) ,(int)(maxx/22.0*(i+1)),maxy);
        sprintf(chaine, "%d", i);
        XDrawString(g.dpy, g.win, g.gcontext, (int)(maxx/22.0*(i+1)-4), 420, chaine, strlen(chaine));
        if (h[i]>0) {
            sprintf(chaine, "%d", h[i]);
            XDrawString(g.dpy, g.win, g.gcontext, (int)(maxx/22.0*(i+1)-4), 75, chaine, strlen(chaine));
        }
    }
    strcpy(chaine, "Occurences");
    XDrawString(g.dpy, g.win, g.gcontext, maxx-100, 50, chaine, strlen(chaine));
    sprintf(chaine, "Notes [%d]", countHisto(h));
    XDrawString(g.dpy, g.win, g.gcontext, 10, 445, chaine, strlen(chaine));
    sprintf(chaine, "Moyenne : %f", meanHisto(h));
    XDrawString(g.dpy, g.win, g.gcontext, 10, 470, chaine, strlen(chaine));
}