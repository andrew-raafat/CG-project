
void recursionFloodFill(HDC hdc, int x, int y, COLORREF bc, COLORREF fc)
{
    cout<<"Flood Filling from Point: " << x << " " << y << endl;
    COLORREF c=GetPixel(hdc, x, y);
    if (c==bc || c==fc) return;
    SetPixel(hdc, x, y, fc);
    recursionFloodFill(hdc, x+1, y, bc, fc);
    recursionFloodFill(hdc, x-1, y, bc, fc);
    recursionFloodFill(hdc, x, y-1, bc, fc);
    recursionFloodFill(hdc, x, y+1, bc, fc);
}

void non_recFloodFill(HDC hdc, int x, int y, COLORREF bc, COLORREF fc)
{
    cout<<"Flood Filling from Point: " << x << " " << y << endl;
    stack<Point> s;
    s.push(Point(x,y));
    while(!s.empty())
    {
        Point p=s.top();
        s.pop();
        COLORREF c=GetPixel(hdc, p.x, p.y);
        if(c==bc || c==fc) continue;
        SetPixel(hdc, p.x, p.y, fc);
        s.push(Point(p.x+1,p.y));
        s.push(Point(p.x-1,p.y));
        s.push(Point(p.x,p.y+1));
        s.push(Point(p.x,p.y-1));
    }
}
