#include<ntddk.h>
#include <wdm.h>

extern "C"
static VOID Unload(DRIVER_OBJECT * pDriverObj)
{
    UNREFERENCED_PARAMETER(pDriverObj);
}

extern "C"
NTSTATUS DriverEntry(DRIVER_OBJECT * pDriverObj, UNICODE_STRING * pRegPath)
{

    UNREFERENCED_PARAMETER(pDriverObj);
    UNREFERENCED_PARAMETER(pRegPath);

    __asm
    {

        ; Шаг один выключение кеша

        mov eax, cr0
        or eax, 1 << 30
        mov cr0, eax

    }

    pDriverObj->DriverUnload = Unload;
    return STATUS_SUCCESS;
}