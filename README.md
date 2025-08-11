# Trenes Argentina 

![Leonardo_Phoenix_09_Imagen_con_fondo_tecnologico_pero_orientad_3 (1)](https://github.com/user-attachments/assets/25ef26ce-cf2f-4755-a95c-00e1e15a08d1)


## Proyecto Final 2°do cuatrimestre Facultad UTN

El proyecto consta en simular un sistema de gestion de una plataforma de TRENES, donde tenemos 2 roles que son USUARIO y ADMINISTRADOR.
<img width="1725" height="879" alt="image" src="https://github.com/user-attachments/assets/7324f2ac-d76d-4a8a-b1a3-7e5f32df0368" />

En la seccion USUARIO vamos a poder crearnos como usuarios lo que nos permitira:

### Sacar boleto:
Esta opcion nos permitira poder sacar un boleto ingresando nombre de ESTACION ORIGEN y ESTACION DESTINO, al final nos mostrara la tarifa del recorrido.

### VER TRENES:
Aqui vamos a poder ver la lista de trenes disponible, la capacidad y asientos disponibles del mismo.

### VER ESTACIONES:
Ver estaciones nos permitira ver que estaciones esta disponibles y en el caso de si habria alguna que por ulgun motivo no este operativa ( reforma, en mantenimiento,etc) nos indicara NO ACTIVO.

### VER TARIFA:
Podemos ver con anteiroridad el costo de la tarifa de estacion a estacion.

### REGISTRARSE:
En esta opcion nos podemos crear un usuario ingresando los datos, como nombre, apellido, email, nombre de usuario y contraseña, el mismo sistema nos creara un ID automatico. Es inprecindible crear un usario, en caso contrario no poodremos generar ninguna de las acciones anteriormente mencionada.

### DAR DE BAJA:
Si por algun motivo queremos darnos de baja ya sea por datos mal cargados o porque ya no vamos a utilizar mas el sistema podremos haccerlo desde aqui.

### HISTORIAL DE BOLETOS:
Desde aca podremos ver un historial de todos nuestros viajes donde podremos visualizar estacion origen, destino, valor de la tarifa, la fecha y hora del viaje.

<img width="1875" height="720" alt="image" src="https://github.com/user-attachments/assets/6c7979cc-3234-4e70-8d24-823714f4f77e" />



La opcion ADMINISTRADOR es la que lleva adelante toda la gestion del sistema con metodo ABML alta, baja , modificacion y listados. Cuando ingresemos por primera vez al sistema solo detectara que es el primer ingreso y nos pedira crear un USUARIO que seria el administrador master, que es EL QU ETENDFRA  que autoriza las modificaciones y tiene algunas acciones adicionales como borrar administradores o crearlos solo el administrador master puede realizar estas acciones.

En el caso que el ADMINISTRADOR esta inactivo o dado de baja no podra ingresar al sistema.

<img width="1778" height="669" alt="image" src="https://github.com/user-attachments/assets/4a451c44-2067-401a-bc60-fb51a4061ece" />

En este MENU principal vamos a tener acceso a los SUB-MENU de:

***PASAJERO:***
Donde podremos realizar todas las acciones ligadas a pasajeros crear, dar de baja. Listar en Orden alfabetico o por ID, podremos buscar con numero de ID, por nombre , apellido y email o bien podremos modificar cualquier atributo que deseemos como nombre, apellido, email, nombre de usuario o contraseña.
Contas con la opcion de informes donde podras ver la cantidad de Pasajeros activos y no activos.
Dentro de cada SUB MENU tendremos las opciones antariormente mencionadas con relacion a los listados y ocion de buscar por lo que se desee.

<img width="1637" height="719" alt="image" src="https://github.com/user-attachments/assets/38f781ee-b26a-4921-97fb-0783e69a3104" />

Asi esta definida la calse con sus atributos y metodos.

````
class Pasajero{

    private:
        int _idPasajero;
        char _nombre[30];
        char _apellido[30];
        char _dni[10];
        char _email[50];
        bool _estado;

    public:
        /// CONSTRUCTORES
        Pasajero();
        Pasajero(int id, const char* nombre, const char* apellido, const char* dni, const char* email, bool estado);

        /// METODOS "GET"
        int getIDPasajero();
        const char* getNombre();
        const char* getApellido();
        const char* getDni();
        const char* getEmail();
        bool getEstado();

        /// METODOS "SET"
        void setIDPasajero(int id);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setDni(const char* dni);
        void setEmail(const char* email);
        void setEstado(bool estado);

        /// METODOS GENERALES
        void cargar(int id = 0, char *dni = (char*)"NADA");
        void mostrar();
        std::string toCSV();
};
````


***TRENES:***
Donde podremos realizar todas las acciones ligadas con los TRENES podremos crear, dar de baja. Listar por ID o por su estado ACTIVO o NO ACTIVO, podremos buscar con numero de ID y por su estado o bien podremos modificar la disponibilidadd de cada TREN.
Contas con la opcion de informes donde podras ver la cantidad de TRENES activos y no activos.
Dentro de cada SUB MENU tendremos las opciones antariormente mencionadas con relacion a los listados y ocion de buscar por lo que se desee.

<img width="1644" height="734" alt="image" src="https://github.com/user-attachments/assets/d22ded1b-49f5-4324-999f-e3c0aa6d1648" />

Asi esta definida la calse con sus atributos y metodos.

````
class Tren{

    private:
        int _idTren;
        bool _capacidadDisponible[15];
        bool _estado;

    public:
        /// CONSTRUCTORES
        Tren();
        Tren(int id);

        /// METODOS "GET"
        int getIDTren();
        bool getCapacidadDisponible(int pos);
        bool getEstado();

        /// METODOS "SET"
        void setIDTren(int id);
        void setCapacidadDisponible(int pos, bool estado);
        void setEstado(bool estado);

        /// METODOS GENERALES
        void cargar(int id = 0);
        void mostrar();
        std::string toCSV();

        int getCantidadAsientos();
};
````

***ESTACIONES:***
Donde podremos realizar todas las acciones ligadas con los ESTACIONES podremos crear, dar de baja, listar por ID, por su estado ACTIVO o NO ACTIVO y por nombre de estacion de forma alfabetica, podremos buscar con numero de ID,nombre o su estado o bien podremos modificar el estado de cada estacion o el nombre.
Contas con la opcion de informes donde podras ver la cantidad de ESTACIONES activos y no activos.
Dentro de cada SUB MENU tendremos las opciones antariormente mencionadas con relacion a los listados y ocion de buscar por lo que se desee.

<img width="1633" height="711" alt="image" src="https://github.com/user-attachments/assets/e86ae2a2-cd78-49a1-b179-1c8b873d6e66" />

Asi esta definida la calse con sus atributos y metodos.

````
class Estacion{

    private:
        int _idEstacion;
        char _nombreEstacion[30];
        bool _estado;

    public:
        /// CONSTRUCTORES
        Estacion();
        Estacion(int id, const char *nombre, bool estado);

        /// METODOS "GET"
        int getIDEstacion();
        const char *getNombreEstacion();
        bool getEstado();

        
        void setIDEstacion(int id);
        void setNombreEstacion(const char *nombreEstacion);
        void setEstado(bool estado);


        void cargar(int id = 0, char *dni = (char*)"NADA");
        void mostrar();
        std::string toCSV();
};

````

***TARIFA:***
Donde podremos realizar todas las acciones ligadas con los TARIFAS podremos crear una tarifa nueva, dar de baja, eliminar nua tarifa, listar por ID, por ESTACION de origen o ESTACION  destino y por manera creciente segun importe de tarifa, podremos buscar con numero de ID de tarifa o por sus importes y podremos modificar el importe de cada tarifa.
Contas con la opcion de informes donde podras ver la cantidad de TARIFAS mas altas, mas bajas y el promedio de tarifa.
Dentro de cada SUB MENU tendremos las opciones antariormente mencionadas con relacion a los listados y ocion de buscar por lo que se desee.

<img width="1630" height="710" alt="image" src="https://github.com/user-attachments/assets/94471853-374a-4435-a5aa-01615df0bc0a" />

Asi esta definida la calse con sus atributos y metodos.

````
class Tarifa{

    private:
        int _idTarifa;
        Estacion _estacionOrigen;
        Estacion _estacionDestino;
        float _tarifa;

    public:
        /// CONSTRUCTORES
        Tarifa();
        Tarifa(int idTarifa, Estacion origen, Estacion destino, float tarifa);

        /// METODOS "GET"
        int getIDTarifa();
        Estacion getEstacionOrigen();
        Estacion getEstacionDestino();
        float getTarifa();

        /// METODOS "SET"
        void setIDTarifa(int id);
        void setEstacionOrigen(Estacion origen);
        void setEstacionDestino(Estacion destino);
        void setTarifa(float tarifa);

        /// METODOS GENERALES
        float calcularValorTarifa(Estacion origen, Estacion destino);
        void cargar(int id = 0);
        void mostrar();
        std::string toCSV();
};
````

***BOLETO:***
Donde podremos realizar todas las acciones ligadas con los BOLETO podremos crear un BOLETO nuevo, dar de baja, eliminar un boleto, listar por ID de boleto, por ID de tren, por DNI del pasajero, por ID de estacion origen o destino y por fecha, podremos buscar con numero de ID de boleto, por ID de TREN o DNI  de pasajero. En este caso no se podra modificar boleto ya que se genera automaticamente.
Contas con la opcion de informes donde podras ver la cantidad de BOLETOS, total de recaudado, estacion con mayor venta de pasajesy los boletos mas caros.
Dentro de cada SUB MENU tendremos las opciones antariormente mencionadas con relacion a los listados y ocion de buscar por lo que se desee.

<img width="1731" height="715" alt="image" src="https://github.com/user-attachments/assets/af018023-30b9-4e1c-8d8b-c8566cb39982" />

Asi esta definida la calse con sus atributos y metodos.

````
class Boleto{

    private:
        int _idBoleto;
        int _idTren;
        char _dniPasajero[10];
        Estacion _estacionOrigen;
        Estacion _estacionDestino;
        float _precioPagado;
        time_t _fechaHoraSistema;

    public:
        /// CONSTRUCTORES
        Boleto();
        Boleto(int idBoleto, int idTren, const char *dniPasajero, Estacion estacionOrigen, Estacion estacionDestino, float precioPagado);

        /// METODOS "GET"
        int getIDBoleto();
        int getIDTren();
        const char *getDniPasajero();
        Estacion getEstacionOrigen();
        Estacion getEstacionDestino();
        float getPrecioPagado();
        time_t &getFechaHoraSistema();

        /// METODOS "SET"
        void setIDBoleto(int id);
        void setIDTren(int id);
        void setDniPasajero(const char *dni);
        void setEstacionOrigen(Estacion origen);
        void setEstacionDestino(Estacion destino);
        void setPrecioPagado(float precioPagado);
        void setFechaHoraSistema(time_t fechaHoraSistema);

        /// METODOS GENERALES
        void mostrar();
        std::string toCSV();
};

````

***ADMINISTRADOR:***
Donde podremos realizar todas las acciones ligadas con los ADMINISTRADORES podremos crear un nuevo ADMINISTRADOR, dar de baja, eliminar, listar por ID, por nombre, por apellido o por email, podremos buscar administradores por NOMBRE, por Apellido o por ID. Tambien tenemos la opcion de poder modificar cualquier atributo al administrador. Cabe destacar que todas estas opciones estan funcionales solo al ADMINISTRADOR MASTER. 
Contas con la opcion de listar por Nombre , por apellido o por ID.
Dentro de cada SUB MENU tendremos las opciones antariormente mencionadas con relacion a los listados y ocion de buscar por lo que se desee.

<img width="1625" height="701" alt="image" src="https://github.com/user-attachments/assets/b430d353-bd69-4339-a0c8-62aa9104c5b5" />

Asi esta definida la calse con sus atributos y metodos.

````
class Administrador{

    private:
        int _idAdministrador;
        char _nombre[30];
        char _apellido[30];
        char _dni [10];
        char _usuario[30];
        char _contrasenia[30];
        bool _estado;

    public:

        /// CONSTRUCTORES
        Administrador();
        Administrador(int id, const char *dni, const char *nombre, const char *apellido, const char *usuario, const char *contrasenia, bool estado);

        /// METODOS "GET"
        int getIdAdministrador();
        const char *getNombre();
        const char *getApellido();
        const char *getDni();
        const char *getUsuario();
        const char *getContrasenia();
        bool getEstado();

        /// METODOS "SET"
        void setIdAdministrador(int id);
        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setDni(const char *dni);
        void setUsuario(const char *apellido);
        void setContrasenia(const char *constrasenia);
        void setEstado(bool estado);

        /// METODOS GENERALES
        void cargar(int id = 0, char *dni = (char*)"NADA");
        void mostrar();
        std::string toCSV();

};

````

***CONFIGURACIONES:***
Por ultimo tenemos una opcion CONFIGURACIONES donde podremos realizar copia de seguridad, backup o descargar en formato csv para excel de cada clase o tenemos una opcion donde podremos realizar de todos a la vez.

<img width="1589" height="597" alt="image" src="https://github.com/user-attachments/assets/6b25c928-62d9-433d-917b-3a440419b817" />

Adjunto un duagrma DER para observar con mas detalle las relaciones de tablas , sus PK y sus FK.

<img width="940" height="713" alt="image" src="https://github.com/user-attachments/assets/a9162ce2-e9ce-4619-86f0-5c81102a5e48" />


