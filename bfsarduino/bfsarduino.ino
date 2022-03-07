const int Size = 20;
const int n = 6;
int arr[Size], p = 0;
int Q[Size], f = 0, r = 0;
int AM[n][n] = {{0,1,1,1,0,0},{1,0,1,0,1,0},{1,1,0,0,0,1},{1,0,0,0,1,1},{0,1,0,1,0,1},{0,0,1,1,1,0}};
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;

void bfs(int n, int Vis[], int AM[][6], int src)
{
  int u, v;
  Vis[src] = 1;
  Q[r] = src;
  while (f <= r)
  {
    u = Q[f++];
    arr[p++] = u;
    for (v = 0; v < n; v++)
    {
      if (AM[u][v] == 1 && Vis[v] == 0)
      {
        Q[++r] = v;
        Vis[v] = 1;
      }
    }
  }
}

void set(int Vis[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    Vis[i] = 0;
  }
}
void bfs_function()
{
  int i, Vis[Size], src = 0;
  set(Vis, n);
  bfs(n, Vis, AM, src);
  for (i = 0; i < n; i++)
  {
    if (Vis[i] == 0)
    {
      src = i;
      r = f;
      bfs(n, Vis, AM, src);
    }
  }
  // traversal of the bfs
}
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  bfs_function();
  for (i = 0; i < n; i++)
  {
    switch (arr[i])
    {
      case 0 :
        digitalWrite(led1, HIGH);
        delay(500);
        break;
      case 1 :
        digitalWrite(led2, HIGH);
        delay(500);
        break;
      case 2 :
        digitalWrite(led3, HIGH);
        delay(500);
        break;
      case 3 :
        digitalWrite(led4, HIGH);
        delay(500);
        break;
      case 4 :
        digitalWrite(led5, HIGH);
        delay(500);
        break;
      case 5 :
        digitalWrite(led6, HIGH);
        delay(500);
        break;
    }
  }
  delay(100);
  for (i = 0; i < n; i++)
  {
    switch (arr[i])
    {
      case 0 :
        digitalWrite(led1, LOW);
        delay(500);
        break;
      case 1 :
        digitalWrite(led2, LOW);
        delay(500);
        break;
      case 2 :
        digitalWrite(led3, LOW);
        delay(500);
        break;
      case 3 :
        digitalWrite(led4, LOW);
        delay(500);
        break;
      case 4 :
        digitalWrite(led5, LOW);
        delay(500);
        break;
      case 5 :
        digitalWrite(led6, LOW);
        delay(500);
        break;
    }
  }
  delay(250);

}
