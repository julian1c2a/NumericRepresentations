#ifndef MEMORY_HANDLER_HPP_INCLUDED
#define MEMORY_HANDLER_HPP_INCLUDED

#include "dig_t.hpp"

using namespace std;

using par_dir_t = std::pair<uchint, uchint>;
using func_refn2digs_prim_t = std::map<std::string, par_dir_t>;
using func_refdig_prim_t = std::map<std::string, par_dir_t>;

namespace details {

template <typename aT, template <uchint> class T, usint num_vars, uchint B>
struct cp_new {
private:
  static aT *contruye_lista_de_variables(aT *var_list) {
    var_list = new aT[num_vars];
    return var_list;
  }

public:
  void operator()(aT **var_list_list) {
    static_cast<T<B> *>(contruye_lista_de_variables(var_list_list[B]));
    cp_new<aT, T, num_vars, B - 1u>(var_list_list);
  }
};

template <typename aT, template <uchint> class T, usint num_vars>
struct cp_new<aT, T, std::numeric_limits<uchint>::max()> {
private:
  static aT **contruye_lista_de_listas_de_variables(aT **var_list_list) {
    var_list_list = new aT *[std::numeric_limits<uchint>::max()];
    return var_list_list;
  }
  static aT *contruye_lista_de_variables(aT *var_list) {
    var_list = new aT[num_vars];
    return var_list;
  }

public:
  void operator()(aT **var_list_list) {
    construye_lista_de_lista_de_variables(var_list_listlist_list);
    static_cast<T<std::numeric_limits<uchint>::max()> *>(
        contruye_lista_de_variables(
            var_list_list[std::numeric_limits<uchint>::max()]));
    cp_new<aT, T, num_vars, std::numeric_limits<uchint>::max() - 1>(
        var_list_list);
  }
};

template <typename aT, template <uchint> class T, usint num_vars>
struct cp_new<2> {
private:
  static aT *contruye_lista_de_variables(aT *var_list) {
    var_list = new aT[num_vars];
    return var_list;
  }

public:
  void operator()(aT **var_list_list) {
    static_cast<T<2u> *>(contruye_lista_de_variables(var_list_list[2u]));
    cp_new<aT, T, num_vars, 1u>(var_list_list);
  }
};

template <typename aT, template <uchint> class T, usint num_vars>
struct cp_new<1u> {
  void operator()(aT **var_list_list) {
    var_list_list[1u] = nullptr;
    cp_new<aT, T, num_vars, 0u>(var_list_list);
  }
};

template <typename aT, template <uchint> class T, usint num_vars>
struct cp_new<0u> {
  void operator()(aT **var_list_list) { var_list_list[0u] = nullptr; }
};

template <typename aT, template <uchint> class T, uchint B> struct cp_delete {
private:
  static void destruye_lista_de_variables(aT *var_list) { delete[] matd[B]; }

public:
  void operator()(aT **var_list_list) {
    destruye_lista_de_variables(var_list_list[B]);
    cp_delete<aT, T, B - 1>(var_list_list);
  }
};

template <typename aT, template <uchint> class T>
struct cp_delete<aT, T, std::numeric_limits<uchint>::max()> {
private:
  static void contruye_lista_de_variables(aT *var_list) {
    delete[] matd[std::numeric_limits<uchint>::max()];
  }

public:
  void operator()(aT **var_list_list) {
    destruye_lista_de_variables(
        var_list_list[std::numeric_limits<uchint>::max()]);
    cp_delete<aT, T, std::numeric_limits<uchint>::max() - 1u>(var_list_list);
  }
};

template <typename aT, template <uchint> class T> struct cp_delete<2u> {
private:
  static void contruye_lista_de_variables(aT *var_list) {
    destruye_lista_de_variables(var_list_list[2u]);
  }

public:
  void operator()(aT **var_list_list) {
    static_cast<T<2u> *>(contruye_lista_de_variables(var_list_list[2u]));
    cp_delete<aT, T, 1>(var_list_list);
  }
};

template <typename aT, template <uchint> class T> struct cp_delete<1u> {
  void operator()(aT **var_list_list) {
    if (var_list_list[1u] != nullptr)
      delete var_list_list[1u];
    cp_delete<aT, T, 0u>(var_list_list);
  }
};

template <typename aT, template <uchint> class T, usint num_vars>
struct cp_delete<0u> {
  void operator()(aT **var_list_list) {
    if (var_list_list[0u] != nullptr)
      delete var_list_list[0u];
    delete[] var_list_list;
  }
};
} // namespace details

template <typename aT, template <uchint> class T, usint num_vars>
  requires(num_vars > 0)
aT **construye_matriz_de_variables(aT **matd) {
  details::cp_new<aT, T, num_vars, std::numeric_limits<uchint>::max()>(matd);
  return matd;
}

template <typename aT, template <uchint> class T>
void destruye_matriz_de_variables(aT **matd) {
  details::cp_delete<aT, T, std::numeric_limits<uchint>::max()>(matd);
}

using INT = long long int;

template <usint num_vars>
  requires(num_vars > 0)
INT **construye_matriz_de_variables<INT, INT>(INT **matd) {
  matd = new (INT *);
  *matd = new INT[num_vars];
  return matd;
}

template <> void destruye_matriz_de_variables<INT, INT>(INT **matd) {
  delete *matd;
  delete[] matd;
}

using UINT = unsigned long long int;

template <usint num_vars>
UINT **construye_matriz_de_variables<UINT, UINT>(UINT **matd) {
  matd = new (UINT *);
  *matd = new UINT[num_vars];
  return matd;
}
template <> void destruye_matriz_de_variables<UINT, UINT>(UINT **matd) {
  delete *matd;
  delete[] matd;
}

template <typename aT, template <uchint> class T> class func_refvar_t {
private:
  vector<vector<bool>> mapmem;
  map<string, par_dir_t> mapvd;
  aT **matd;
  vector<uint> cuentavars;

  // Mira si un nombre de variable esta disponible y si esta libre un lugar
  // concreto de "memoria". Arregla el mapa de memoria. Si ha tenido exito y se
  // puede insertar la variable devuelve true, sino false.
  bool insert(string nombre, uchint base, uchint var_base) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    const map<string, par_dir_t>::iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if (((*it).second.second == var_base) or ((*it).first == nombre))
        return false;
    }
    if (mapmem[base][var_base] == false) {
      mapvd.insert(std::make_pair<std::string, par_dir_t>(
          nombre, std::make_pair<uchint, uchint>(base, var_base)));
      mapmem[base][var_base] = true;
      return true;
    } else
      return false;
  }

  func_refvar_t(const func_refvar_t &);

public:
  func_refvar_t() {
    // inicia_matriz_digs_y_pp(matd,256u,256u);
    matd = construye_matriz_de_variables<ppT, pT, T>(matd);
    mapmem.resize(256);
    cuentavars.resize(256);
    for (uint I = 0; I < 256; ++I) {
      mapmem[I].resize(256);
      cuentavars[I] = 0;
      for (uint J = 0; J < 256; ++J) {
        mapmem[I][J] = false;
      }
    }
  }

  ~func_refvar_t() { destruye_matriz_de_variables<T, T>(matd); }

private: // BAJO NIVEL
  // encuentra espacio para una variable de base B
  // devuelve true si ha tenido exito y false si no
  bool escribe_var(string nombre, uchint base, uchint var_base) {
    bool se_puede_insertar = false;
    if (cuentavars[base] <= 256) {
      uint var_base = 0;
      while (!se_puede_insertar) {
        se_puede_insertar = insert(nombre, base, var_base);
        if (!se_puede_insertar)
          var_base++;
      }
      if (se_puede_insertar)
        (cuentavars[base])++;
    }
    return se_puede_insertar;
  }

public:
  // borra el lugar de una variable de base B
  void borra_var(string nombre) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    map<string, par_dir_t>::const_iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if ((*it).first == nombre) {
        mapmem[(*it).second.first][(*it).second.second] = false;
        --cuentavars[(*it).second.first];
        mapvd.erase(it); // ponerlo a 0
        return;
      }
    }
    return;
  }

  bool existe_lugar_de_base(uchint Base) {
    bool ret = true;
    for (uint I = 0; I < 256; ++I) {
      ret = ret and mapmem[Base][I];
      if (!ret)
        return true;
    }
    return false;
  }

  bool este_nombre_ya_ha_sido_declarado(string nombre) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    map<string, par_dir_t>::const_iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if ((*it).first == nombre) {
        return true;
      }
    }
    return false;
  }

  template <const uchint B> T<B> get(string nombre) {
    return (reinterpret_cast<T<B> *>(matd[B]))[mapvd[nombre].second];
  }

  template <const uchint B> bool operator()(string nombre, string lhs) {
    T<B> temp(lhs);
    bool se_puede_hacer = este_nombre_ya_ha_sido_declarado(nombre);
    if (se_puede_hacer)
      (reinterpret_cast<T<B> *>(matd[B]))[mapvd[nombre].second] = temp;
    return se_puede_hacer;
  }
};

class func_refvar_t<INT **, INT *, INT> {
private:
  vector<vector<bool>> mapmem;
  map<string, par_dir_t> mapvd;
  INT **matd;
  vector<uint> cuentavars;

  // Mira si un nombre de variable está disponible y si está libre un lugar
  // concreto de "memoria". Arregla el mapa de memoria. Si ha tenido exito y se
  // puede insertar la variable devuelve true, sino false.
  bool insert(string nombre, uchint base, uchint var_base) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    const map<string, par_dir_t>::iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if (((*it).second.second == var_base) or ((*it).first == nombre))
        return false;
    }
    if (mapmem[base][var_base] == false) {
      mapvd.insert(std::make_pair<std::string, par_dir_t>(
          nombre, std::make_pair<uchint, uchint>(base, var_base)));
      mapmem[base][var_base] = true;
      return true;
    } else
      return false;
  }

  func_refvar_t(const func_refvar_t &) = delete;

public:
  func_refvar_t() {
    // inicia_matriz_digs_y_pp(matd,256u,256u);
    matd = construye_matriz_de_variables<INT **, INT *, INT>(matd);
    mapmem.resize(256);
    cuentavars.resize(256);
    for (uint I = 0; I < 256; ++I) {
      mapmem[I].resize(256);
      cuentavars[I] = 0;
      for (uint J = 0; J < 256; ++J) {
        mapmem[I][J] = false;
      }
    }
  }

  ~func_refvar_t() { destruye_matriz_de_variables<INT **, INT *, INT>(matd); }

private: // BAJO NIVEL
  // encuentra espacio para una variable de base B
  // devuelve true si ha tenido exito y false si no
  bool escribe_var(string nombre, uchint base, uchint var_base) {
    bool se_puede_insertar = false;
    if (cuentavars[base] <= 256) {
      uint var_base = 0;
      while (!se_puede_insertar) {
        se_puede_insertar = insert(nombre, base, var_base);
        if (!se_puede_insertar)
          var_base++;
      }
      if (se_puede_insertar)
        (cuentavars[base])++;
    }
    return se_puede_insertar;
  }

public:
  // borra el lugar de una variable de base B
  void borra_var(string nombre) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    map<string, par_dir_t>::const_iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if ((*it).first == nombre) {
        mapmem[(*it).second.first][(*it).second.second] = false;
        --cuentavars[(*it).second.first];
        mapvd.erase(it); // ponerlo a 0
        return;
      }
    }
    return;
  }

  bool existe_lugar_de_base(uchint Base) {
    bool ret = true;
    for (uint I = 0; I < 256; ++I) {
      ret = ret and mapmem[Base][I];
      if (!ret)
        return true;
    }
    return false;
  }

  bool este_nombre_ya_ha_sido_declarado(string nombre) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    map<string, par_dir_t>::const_iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if ((*it).first == nombre) {
        return true;
      }
    }
    return false;
  }

  INT get(string nombre) { return (*matd[B])[mapvd[nombre].second]; }

  bool operator()(string nombre, string lhs) {
    INT temp(lhs);
    bool se_puede_hacer = este_nombre_ya_ha_sido_declarado(nombre);
    if (se_puede_hacer)
      (*matd)[mapvd[nombre].second] = temp;
    return se_puede_hacer;
  }
};

class func_refvar_t<UINT **, UINT *, UINT> {
private:
  vector<vector<bool>> mapmem;
  map<string, par_dir_t> mapvd;
  UINT **matd;
  vector<uint> cuentavars;

  // Mira si un nombre de variable está disponible y si está libre un lugar
  // concreto de "memoria". Arregla el mapa de memoria. Si ha tenido exito y se
  // puede insertar la variable devuelve true, sino false.
  bool insert(string nombre, uchint base, uchint var_base) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    const map<string, par_dir_t>::iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if (((*it).second.second == var_base) or ((*it).first == nombre))
        return false;
    }
    if (mapmem[base][var_base] == false) {
      mapvd.insert(std::make_pair<std::string, par_dir_t>(
          nombre, std::make_pair<uchint, uchint>(base, var_base)));
      mapmem[base][var_base] = true;
      return true;
    } else
      return false;
  }

  func_refvar_t(const func_refvar_t &);

public:
  func_refvar_t() {
    // inicia_matriz_digs_y_pp(matd,256u,256u);
    matd = construye_matriz_de_variables<UINT **, UINT *, UINT>(matd);
    mapmem.resize(256);
    cuentavars.resize(256);
    for (uint I = 0; I < 256; ++I) {
      mapmem[I].resize(256);
      cuentavars[I] = 0;
      for (uint J = 0; J < 256; ++J) {
        mapmem[I][J] = false;
      }
    }
  }

  ~func_refvar_t() {
    destruye_matriz_de_variables<UINT **, UINT *, UINT>(matd);
  }

private: // BAJO NIVEL
  // encuentra espacio para una variable de base B
  // devuelve true si ha tenido exito y false si no
  bool escribe_var(string nombre, uchint base, uchint var_base) {
    bool se_puede_insertar = false;
    if (cuentavars[base] <= 256) {
      uint var_base = 0;
      while (!se_puede_insertar) {
        se_puede_insertar = insert(nombre, base, var_base);
        if (!se_puede_insertar)
          var_base++;
      }
      if (se_puede_insertar)
        (cuentavars[base])++;
    }
    return se_puede_insertar;
  }

public:
  // borra el lugar de una variable de base B
  void borra_var(string nombre) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    map<string, par_dir_t>::const_iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if ((*it).first == nombre) {
        mapmem[(*it).second.first][(*it).second.second] = false;
        --cuentavars[(*it).second.first];
        mapvd.erase(it); // ponerlo a 0
        return;
      }
    }
    return;
  }

  bool existe_lugar_de_base(uchint Base) {
    bool ret = true;
    for (uint I = 0; I < 256; ++I) {
      ret = ret and mapmem[Base][I];
      if (!ret)
        return true;
    }
    return false;
  }

  bool este_nombre_ya_ha_sido_declarado(string nombre) {
    map<string, par_dir_t>::iterator it = mapvd.begin();
    map<string, par_dir_t>::const_iterator itend = mapvd.end();
    for (; it != itend; ++it) {
      if ((*it).first == nombre) {
        return true;
      }
    }
    return false;
  }

  template <const uchint B> UINT get(string nombre) {
    return (*matd)[mapvd[nombre].second];
  }

  bool operator()(string nombre, string lhs) {
    UINT temp(lhs);
    bool se_puede_hacer = este_nombre_ya_ha_sido_declarado(nombre);
    if (se_puede_hacer)
      *matd[mapvd[nombre].second] = temp;
    return se_puede_hacer;
  }
};

#endif // MEMORY_HANDLER_HPP_INCLUDED
