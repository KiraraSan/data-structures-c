#include "header.h"

DataParent makeDataParent(int id, string ruangan, bool status, int temp) {
    DataParent data;
    
    data.id = id;
    strcpy(data.ruangan, ruangan);
    if (temp == 1) {
    	data.status = true;
	} else {
		data.status = false;
	}
	
    return data;
}

DataChild makeDataChild(string noPlat, string merek, float bensin) {
    DataChild data;
    
    strcpy(data.noPlat, noPlat);
    strcpy(data.merek, merek);
    data.bensin = bensin;
    
    return data;
}

bool isParentUnik(Multilist l, int id) {
    AddressParent temp = l.firstParent;
    
    for (temp = l.firstParent; temp != NULL; temp = temp->next) {
        if (temp->data.id == id) {
            return false;
        }
    }
    return true;
}

bool isChildUnik(Multilist l, string noPlat) {
    AddressParent p;
    AddressChild c;
    
    for (p = l.firstParent; p != NULL; p = p->next) {
        for (c = p->firstChild; c != NULL; c = c->next) {
            if (strcmpi(c->data.noPlat, noPlat) == 0) {
                return false;
            }
        }
        return true;
    }
}

void distribusi(Multilist *l) {
    AddressParent p, x = NULL;
    AddressChild c;
    Multilist n;
    createEmpty(&n);
    
    for (p = l->firstParent; p != NULL; p = p->next)
        insertLastParent(&n, p->data);

    int count = 0;
    
    for (p = l->firstParent; p != NULL; p = p->next) {
        if (!haveChild(p)) {
            continue;
        }
        for (c = p->firstChild; c != NULL; c = c->next) {
            if (x == NULL)
                x = n.firstParent;
            insertLastChild(n, x->data.id, c->data);
            x = x->next;
        }
    }
    *l = n;
}
