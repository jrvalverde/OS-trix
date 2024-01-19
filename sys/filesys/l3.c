/*****************************************************************
 *                                                               *
 *                         Copyright (c) 1984                    *
 *               Massachusetts Institute of Technology           *
 *                                                               *
 * This material is a component of the TRIX system, developed by *
 * D. Goddeau, J. Sieber, and S. Ward of the                     *
 *                                                               *
 *                          RTS group                            *
 *               Laboratory for Computer Science                 *
 *            Massachusetts Institute of Technology              *
 *                Cambridge, Massachusetts 02139                 *
 *                                                               *
 * Permission to copy this software, to redistribute it, and to  *
 * use it for any purpose is granted, subject to the conditions  *
 * that (1) This copyright notice remain, unchanged and in full, *
 * on any copy or derivative of the software; and (2) that       *
 * references to or documentation of any copy or derivative of   *
 * this software acknowledge its source in accordance with the   *
 * usual standards in academic research.                         *
 *                                                               *
 * MIT has made no warrantee or representation that the          *
 * operation of this software will be error-free, and MIT is     *
 * under no obligation to provide any services, by way of        *
 * maintenance, update, or otherwise.                            *
 *                                                               *
 * In conjunction with products arising from the use of this     *
 * material, there shall be no use of the name of the            *
 * Massachusetts Institute of Technology nor of any adaptation   *
 * thereof in any advertising, promotional, or sales literature  *
 * without prior written consent from MIT in each case.          *
 *                                                               *
 *****************************************************************/


l3tol(p1, p2, count)
register char *p1, *p2;
{
	register int i;

	for(i = 0 ; i<count ; i++) {
#ifdef pdp11
		*p1++ = *p2++;
		*p1++ = 0;
		*p1++ = *p2++;
		*p1++ = *p2++;
#else
		*p1++ = 0;
		*p1++ = *p2++;
		*p1++ = *p2++;
		*p1++ = *p2++;
#endif
	}
	return(i);
}


ltol3(p1, p2, count)
register char *p1, *p2;
{
	register int i;

	for(i=0; i<count; i++) {
#ifdef pdp11
		*p1++ = *p2++;
		if(*p2++ != 0)
			break;
		*p1++ = *p2++;
		*p1++ = *p2++;
#else
		if(*p2++ != 0)
			break;
		*p1++ = *p2++;
		*p1++ = *p2++;
		*p1++ = *p2++;
#endif
	}
	return(i);
}
