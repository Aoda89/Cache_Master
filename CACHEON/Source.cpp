#include<ntddk.h>
#include<wdm.h>

extern "C"
static VOID Unload(DRIVER_OBJECT* pDriverObj)
{
    UNREFERENCED_PARAMETER(pDriverObj);
}

extern "C"
NTSTATUS DriverEntry(DRIVER_OBJECT* pDriverObj, UNICODE_STRING* pRegPath) {

    UNREFERENCED_PARAMETER(pDriverObj);
    UNREFERENCED_PARAMETER(pRegPath);

    __asm
    {

        mov eax, cr0
        and eax, ~(1 << 30)
        mov cr0, eax
        wbinvd


    }
    pDriverObj->DriverUnload = Unload;
    return STATUS_SUCCESS;
}