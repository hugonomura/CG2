/* 
	O primeiro m�todo desenha retas espessas e cont�nuas para coeficientes angulares menores que 1. Para contornar o problema de descontinuidade
para coeficientes angulares maiores que 1, este m�todo foi reformulado de modo a sempre deixar a reta cont�nua.
	O segundo m�todo produz retas menos espessas, por�m ainda espessas em alguns pontos, mas assim como o primeiro m�todo, para coeficientes 
angulares maiores que 1, a reta produz descont�nuidades. Este problema foi contornado da mesma forma.
	O terceiro m�todo produz retas finas e cont�nuas para coeficientes angulares menores que 1. O quarto m�todo � o oposto do primeiro, isso �
produz linhas finas e cont�nuas somente para coeficientes angulares maiores que 1.
	Os tr�s primeiros m�todos falham ao tra�ar uma reta vertical. Desta forma foi implementado um m�todo para tra�ar retas verticais.
	Para tra�ar retas horizontais, apesar dos tr�s primeiros m�todos conseguirem desenhar, foi criado mais um m�todo para tra�ar retas horizontais
para otimizar o tra�ado da reta horizontal.
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


// representa��o 1 de desenhar uma reta
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


// representa��o 2 de desenhar uma reta
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
        

// representa��o 3 de desenhar uma reta
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


// representa��o 4 de desenhar uma reta
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
