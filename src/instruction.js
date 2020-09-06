module.exports = class InstructionManager {
  constructor(file_info) {
    this.inst_map = {};

    for (const file_name in file_info) {
      let file = file_info[file_name];
      if (file.path == '/X86-64 명령어 레퍼런스') {
        this.inst_map[file_name] = file;
      }
    }
  }

  getInstruction(inst) {
    // First check it is all alphabet or - or []
    if(!/^[a-zA-Z\-\[\]]+$/.test(inst)) {
      return null;
    }

    inst = inst.toLowerCase();
    return this.inst_map[inst];
  }
} 