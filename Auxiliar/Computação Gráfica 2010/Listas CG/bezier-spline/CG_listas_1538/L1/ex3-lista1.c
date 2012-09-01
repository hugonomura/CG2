/* 
	O primeiro método desenha retas espessas e contínuas para coeficientes angulares menores que 1. Para contornar o problema de descontinuidade
para coeficientes angulares maiores que 1, este método foi reformulado de modo a sempre deixar a reta contínua.
	O segundo método produz retas menos espessas, porém ainda espessas em alguns pontos, mas assim como o primeiro método, para coeficientes 
angulares maiores que 1, a reta produz descontínuidades. Este problema foi contornado da mesma forma.
	O terceiro método produz retas finas e contínuas para coeficientes angulares menores que 1. O quarto método é o oposto do primeiro, isso é
produz linhas finas e contínuas somente para coeficientes angulares maiores que 1.
	Os três primeiros métodos falham ao traçar uma reta vertical. Desta forma foi implementado um método para traçar retas verticais.
	Para traçar retas horizontais, apesar dos três primeiros métodos conseguirem desenhar, foi criado mais um método para traçar retas horizontais
para otimizar o traçado da reta horizontal.
*/



void retaVertical(int x, int y0, int y, Display *display, Window win,GC gc)
{
    int i;
    for (i = y0 +1; i < y; i++)
    {
        XDrawPoint(display,win,gc,x,i);
    }
}

void retaHorizontal(int x0, int x, int y,Display *display, Window win,GC gc)
{
    int i;
    for (i = x0+1; i < x; i++)
    {
        XDrawPoint(display,win,gc,i,y);
    }
}


// representação 1 de desenhar uma reta
void rep1(int x0, int x, int y0, int y,Display *display, Window win,GC gc)
{
    
    double m, tmp;           
    int i, Y, aux;
    m = (y - y0) / (x - x0);
    if (m < 1 && m > -1)
    {
        if (x < x0)
        {
            aux = x0;
            x0 = x;
            x = aux;

            aux = y;
            y = y0;
            y0 = aux;
        }
        i = x0 + 1;
        while (i != x)
        {
            tmp = (m * (i - x0)) + y0;
            Y = tmp;
            if ( Y - tmp >=0.5){
		Y++;
	    }
	    XDrawPoint(display,win,gc,i,Y);

            Y = tmp;
	    XDrawPoint(display,win,gc,i,Y);
            i++;
        }
    }
    else
    {
        if (y < y0)
        {
            aux = x0;
            x0 = x;
            x = aux;

            aux = y;
            y = y0;
            y0 = aux;
        }
        i = y0 + 1;
        
        while (i != y)
        {
            tmp = x0 + ((i-y0)/m);
            Y = tmp;
            if ( Y - tmp >=0.5){
		Y++;
	    }
	    XDrawPoint(display,win,gc,Y,i);

            Y = tmp;
	    XDrawPoint(display,win,gc,Y,i);
            i++;

        }
    }
}


// representação 2 de desenhar uma reta
void rep2(int x0, int x, int y0, int y,Display *display, Window win,GC gc)
{
    double m, tmp;
    int i, Y, aux;
    m = (y - y0) / (x - x0);
    if (m < 1 && m > -1)
    {
        if (x < x0)
        {
            aux = x0;
            x0 = x;
            x = aux;

            aux = y;
            y = y0;
            y0 = aux;
        }
        i = x0 + 1;
        
        while (i != x)
        {
            tmp = (m * (i - x0)) + y0;
            
            Y = tmp;
            if (Y - 0.25 > tmp && Y - 0.75 < tmp)
            {
                XDrawPoint(display,win,gc,i,Y-1);
            }
            XDrawPoint(display,win,gc,i,Y);
            i++;                    
        }
    }
    else
    {
        if (y < y0)
        {
            aux = x0;
            x0 = x;
            x = aux;

            aux = y;
            y = y0;
            y0 = aux;
        }
        i = y0 + 1;
        
        while (i != y)
        {
            tmp = x0 + ((i - y0) / m);
            
            Y =tmp;
            if (Y - 0.25 > tmp && Y - 0.75 < tmp)
            {
                XDrawPoint(display,win,gc,Y-1,i);
            }
            XDrawPoint(display,win,gc,Y,i);
            i++;
        }
    }

}
        

// representação 3 de desenhar uma reta
void rep3(int x0, int x, int y0, int y,Display *display, Window win,GC gc)
{
    double m,Y;
    int aux, i, tmp;
    m = (y - y0) / (x - x0);

    {
        if (x < x0)
        {
            aux = x0;
            x0 = x;
            x = aux;

            aux = y;
            y = y0;
            y0 = aux;
        }
        i = x0 + 1;
        
        while (i != x)
        {
            tmp = (m * (i - x0)) + y0;

            Y = tmp+0.5;
            XDrawPoint(display,win,gc,i,Y);
            i++;
        }
    }
}


// representação 4 de desenhar uma reta
void rep4(int x0, int x, int y0, int y,Display *display, Window win,GC gc)
{
    double m, tmp;
    int aux, X, i;
    m = (y - y0) / (x - x0);
    if (y < y0)
    {
        aux = x0;
        x0 = x;
        x = aux;

        aux = y;
        y = y0;
        y0 = aux;
    }
    i = y0 + 1;
    
    while (i != y)
    {
        tmp = x0 + ((i - y0) / m);

        X = tmp + 0.5;
        XDrawPoint(display,win,gc,X,i);
        i++;
    }
}
