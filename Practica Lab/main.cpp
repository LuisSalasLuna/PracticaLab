#include <iostream>

using namespace std;
//1
class Empleado{
    private:
        string nombre;
        string apellido;
        double salario;
    public:
        Empleado();
        Empleado(string,string,double);
        string GetNombre();
        string GetApellido();
        double GetSalario();
        double SetSalario(double);
        void Print();
};
    Empleado::Empleado(){
        nombre = "Nombre";
        apellido = "Apellido";
        salario = 0;
    }
    Empleado::Empleado(string N, string A, double S){
        nombre = N;
        apellido = A;
        salario = S;
    }
    string Empleado::GetNombre(){
        return nombre;
    }
    string Empleado::GetApellido(){
        return apellido;
    }
    double Empleado::GetSalario(){
        if(salario/-1 > 0){
            salario = 0;
        }
        return salario;
    }
    double Empleado::SetSalario(double Sa){
        salario=Sa;
    }
    void Empleado::Print(){
    cout<< apellido<<endl;
    }
//2
void OrdenApellido(Empleado Corp[],int tam){
    for(int i=0 ; i < tam-1; i++){
        int m=i;
        for(int j = i+1 ; j < tam; j++){
            if(Corp[m].GetApellido()[0]>Corp[j].GetApellido()[0]){
                    m=j;
            }
        Empleado aux = Corp[m];
        Corp[m]= Corp[i];
        Corp[i] = aux;
        }
    }
}
//3
class Estudiante{
    private:
        string nombre;
        string apellido;
        string codigo;
    public:
        Estudiante();
        Estudiante(string,string,string);
        string GetNombre();
        string GetApellido();
        string GetCodigo();
};
    Estudiante::Estudiante(){
        nombre = "Nombre";
        apellido = "Apellido";
        codigo = "Codigo";
    }
    Estudiante::Estudiante(string N, string A, string C){
        nombre = N;
        apellido = A;
        codigo = C;
    }
    string Estudiante::GetNombre(){
        return nombre;
    }
    string Estudiante::GetApellido(){
        return apellido;
    }
    string Estudiante::GetCodigo(){
        return codigo;
    }
//4
class Curso{
    private:
        string nombre;
        string codigo;
        Estudiante *alumnos;
        int cantidaAlumnos;
    public:
        Curso(string,string,Estudiante*,int);
        Curso(const Curso&);
        //Gets
        string GetNombre();
        string GetCodigo();
        Estudiante *GetAlumnos();
        int GetCantidadAlums();
        //Sets
        string SetNombre(string);
        string SetCodigo(string);
        Estudiante *SetAlumnos(Estudiante*);
        int SetCantidadAlums(int);
        //Aumentar estuds
        void AumentEstuds();
};
    Curso::Curso(string N, string C, Estudiante *A, int cA){
        nombre = N;
        codigo = C;
        alumnos = A;
        cantidaAlumnos = cA;
    }
    Curso::Curso(const Curso& L){
        nombre = L.nombre;
        codigo = L.codigo;
        alumnos = L.alumnos;
        cantidaAlumnos = L.cantidaAlumnos;
    }
    string Curso::GetNombre(){
        return nombre;
    }
    string Curso::GetCodigo(){
        return codigo;
    }
    Estudiante* Curso::GetAlumnos(){
        return alumnos;
    }
    int Curso::GetCantidadAlums(){
        return cantidaAlumnos;
    }
    string Curso::SetNombre(string N){
        nombre = N;
    }
    string Curso::SetCodigo(string C){
        codigo = C;
    }
    Estudiante* Curso::SetAlumnos(Estudiante* A){
        alumnos = A;
    }
    int Curso::SetCantidadAlums(int cA){
        cantidaAlumnos = cA;
    }
    void Curso::AumentEstuds(){
        cantidaAlumnos++;
    }
int main()
{
    //1
    Empleado A("Juan", "Ramos",750);
    Empleado B("Pedro","Vasquez",1000);
    cout << A.GetSalario()*12<<endl;
    cout << B.GetSalario()*12<<endl;
    A.SetSalario(A.GetSalario()- A.GetSalario()/10);
    B.SetSalario(B.GetSalario()- B.GetSalario()/10);
    cout << A.GetSalario()*12<<endl;
    cout << B.GetSalario()*12<<endl;

    cout <<"\n";
    //2
    Empleado C("Angel","Perez",1100);
    Empleado arr[]={B,A,C};
    int tam= 3;
    OrdenApellido(arr,tam);

    for(int i=0 ; i < tam; i++){
        arr[i].Print();
    }

    cout <<"\n";
    //3
    Estudiante X("Luis","Salas","70331221");
    cout <<X.GetNombre()<<endl;
    cout <<X.GetApellido()<<endl;
    cout <<X.GetCodigo()<<endl;
    cout <<"\n";
    Estudiante Y("Rafael","Ochoa","76255248");
    cout <<Y.GetNombre()<<endl;
    cout <<Y.GetApellido()<<endl;
    cout <<Y.GetCodigo()<<endl;

    cout <<"\n";
    //4
    Estudiante arrEst[]={X,Y};
    Curso R("Matematicas","0954",arrEst,2);
    Curso T = R;
    cout <<R.GetNombre()<<endl;
    cout <<R.GetCodigo()<<endl;
    cout <<R.GetAlumnos()<<endl;
    cout <<R.GetCantidadAlums()<<endl;

    cout <<"\n";

    cout <<T.GetNombre()<<endl;
    cout <<T.GetCodigo()<<endl;
    cout <<T.GetAlumnos()<<endl;
    cout <<T.GetCantidadAlums()<<endl;
    //set
    R.SetNombre("Filosofia");
    R.AumentEstuds();

    cout <<"\n";
    //get
    cout <<R.GetNombre()<<endl;
    cout <<T.GetNombre()<<endl;
    cout <<"\n";
    cout <<(arrEst)->GetApellido()<<endl;
    cout <<(arrEst+1)->GetApellido()<<endl;
    cout <<R.GetCantidadAlums()<<endl;

    return 0;
}
