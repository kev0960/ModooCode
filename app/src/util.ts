export function StripPrefixNbsp(str: string): string {
  let i = 0;
  for (; i < str.length; i ++) {
    if (str[i] == ' ') { // This is not space. This is unicode NBSP (U+00A0)
      continue;
    } else {
      break;
    }
  }
  return str.substring(i);
}

export function GetHeaderNum(str: string): number {
  if (!(str[0] == 'h' || str[0] == 'H')) {
    return -1;
  }

  return parseInt(str.substring(1));
}