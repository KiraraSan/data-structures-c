#include "header.h"

void createEmpty(Multilist *l){
	l->firstParent = NULL;
}

bool isEmpty(Multilist l){
	return l.firstParent == NULL;
}

bool haveChild(AddressParent ap){
	return ap->firstChild != NULL;
}

bool isParentUnik(Multilist l, int idDokter){
	AddressParent temp = l.firstParent;
	
	while(temp != NULL){
		if(temp->dataParent.idDokter == idDokter){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

bool isChildUnik(Multilist l, int idPeriksa){
	AddressParent parent = l.firstParent;
	while(parent != NULL){
		AddressChild child = parent->firstChild;
		while(child != NULL){
			if(child->dataChild.idPeriksa == idPeriksa){
				return false;
			}
			child = child->next;
		}
		parent = parent->next;
	}
	return true;
}

AddressParent alokasiParent(DataParent data){
	AddressParent ap;
	
	ap = (AddressParent) malloc(sizeof(NodeParent));
	
	ap->next = NULL;
	ap->firstChild = NULL;
	ap->dataParent = data;
	
	return ap;
}

void insertFirstParent(Multilist *l, DataParent data){
	AddressParent dataParent = alokasiParent(data);
	
	dataParent->next = l->firstParent;
	l->firstParent = dataParent;
}

void insertLastParent(Multilist *l, DataParent data){
	AddressParent dataParent = alokasiParent(data);
	
	if(isEmpty(*l)){
		insertFirstParent(l, data);
		
	}else{
		AddressParent temp = l->firstParent;
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = dataParent;
	}
}

AddressParent findParent(Multilist l, int cariId) {
    AddressParent parentBantu;

    parentBantu = l.firstParent;

    while (parentBantu != NULL) {
        if (parentBantu->dataParent.idDokter == cariId) {
            return parentBantu;
        }

        parentBantu = parentBantu->next;
    }

    return NULL;
}

AddressParent cekUserDokter(Multilist l, string username, string password){
	AddressParent parent;
	parent = l.firstParent;
	
	while(parent != NULL){
		
		if((strcmpi(parent->dataParent.username, username) == 0) && strcmp(parent->dataParent.password, password) == 0){
			return parent;
		}
		
	parent = parent->next;
	
	}
	return NULL;
}

void deleteFirstParent(Multilist *l) {
    AddressParent temp = l->firstParent;

    if (!isEmpty(*l)) {
        deleteAllChild(temp);

        l->firstParent = l->firstParent->next;
        free(temp);
    }
}

void deleteAtParent(Multilist *l, int idParent) {
    AddressParent temp = l->firstParent;
    AddressParent hapus;

    if (!isEmpty(*l)) {
        if (temp->dataParent.idDokter == idParent) {
            deleteFirstParent(l);
        } else {
            while (temp->next != NULL) {
                if (temp->next->dataParent.idDokter == idParent) {
                    hapus = temp->next;
                    temp->next = temp->next->next;

                    deleteAllChild(hapus);
                    free(hapus);
                    break;
                }

                temp = temp->next;
            }
        }
    }
}

void deleteAllChild(AddressParent parent) {
    AddressChild temp;

    while (haveChild(parent)) {
        temp = parent->firstChild;
        parent->firstChild = parent->firstChild->next;

        free(temp);
    }
}
