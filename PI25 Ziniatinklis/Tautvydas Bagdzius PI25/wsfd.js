
// =========================
// NUSTATYMAI (tema, akcento spalva, teksto dydis)
// =========================
(function settingsInit() {
  const LS_KEY = 'wsfd_settings';

  function applySettings(s) {
    if (!s) return;
    // Tema
    document.documentElement.classList.toggle('theme-dark', s.theme === 'dark');
    // Akcento spalva
    document.documentElement.style.setProperty('--wsfd-accent', s.accent || '#ffc107');
    // Teksto mastelis
    const fs = (!s.fontScale || isNaN(+s.fontScale)) ? 1 : +s.fontScale;
    document.documentElement.style.setProperty('--wsfd-font-scale', fs);
  }

  // Įkelti iš localStorage
  let saved = null;
  try { saved = JSON.parse(localStorage.getItem(LS_KEY) || 'null'); } catch(e){}
  applySettings(saved);

  // Jei yra modalas – sujungiam UI su duomenimis
  const modal = document.getElementById('settingsModal');
  if (!modal) return;

  const themeLight = document.getElementById('theme-light');
  const themeDark  = document.getElementById('theme-dark');
  const accent     = document.getElementById('accentColor');
  const fontScale  = document.getElementById('fontScale');
  const btnSave    = document.getElementById('saveSettings');
  const btnReset   = document.getElementById('resetSettings');

  const cur = saved || {
    theme: (document.documentElement.classList.contains('theme-dark') ? 'dark' : 'light'),
    accent: getComputedStyle(document.documentElement).getPropertyValue('--wsfd-accent').trim() || '#ffc107',
    fontScale: getComputedStyle(document.documentElement).getPropertyValue('--wsfd-font-scale').trim() || '1'
  };

  // Užpildyti modalą
  if (themeLight && themeDark) {
    (cur.theme === 'dark' ? themeDark : themeLight).checked = true;
  }
  if (accent) accent.value = cur.accent || '#ffc107';
  if (fontScale) fontScale.value = cur.fontScale || '1';

  // Išsaugoti
  btnSave?.addEventListener('click', () => {
    const next = {
      theme: (themeDark?.checked ? 'dark' : 'light'),
      accent: accent?.value || '#ffc107',
      fontScale: fontScale?.value || '1'
    };
    localStorage.setItem(LS_KEY, JSON.stringify(next));
    applySettings(next);

    // Uždaryti modalą (Bootstrap)
    const modalInst = bootstrap.Modal.getOrCreateInstance(modal);
    modalInst.hide();
  });

  // Atstatyti į numatytus
  btnReset?.addEventListener('click', () => {
    localStorage.removeItem(LS_KEY);
    const defaults = { theme: 'light', accent: '#ffc107', fontScale: '1' };
    applySettings(defaults);
    // Sinchronizuoti UI
    if (themeLight) themeLight.checked = true;
    if (accent) accent.value = defaults.accent;
    if (fontScale) fontScale.value = defaults.fontScale;
  });
})();

// =========================
// FORMOS VALIDACIJA + SĖKMĖS PRANEŠIMAS
// =========================
(function formValidationInit() {
  // Bandome rasti formą per id arba paimam pirmą puslapyje
  const form = document.getElementById('joinForm') || document.querySelector('form');
  if (!form) return;

  // Laukai (palaikau tavo LT id pavadinimus)
  const emailEl   = document.getElementById('paštas') || document.getElementById('email');
  const discEl    = document.getElementById('diskordas') || document.getElementById('discord');
  const gameEl    = document.getElementById('žaidimoVardas') || document.getElementById('gameName');
  const ageEl     = document.getElementById('amžius') || document.getElementById('age');

  const isEmail = (v) => /^\S+@\S+\.\S+$/.test(String(v || '').trim());
  // Discord: "Vardas#1234" arba naujas "@handle" — leisime abu
  const isDiscord = (v) => /^(?:.{2,32}#\d{4}|@?[a-zA-Z0-9_\.]{2,32})$/.test(String(v || '').trim());
  const atLeastOneChecked = () => {
    const boxes = form.querySelectorAll('input[name="pomėgiai"], input[name="interesai[]"], input[name="interesai"]');
    return Array.from(boxes).some(b => b.checked);
  };

  function showError(input, msg) {
    input?.classList.add('is-invalid');
    input?.setAttribute('title', msg);
  }
  function clearError(input) {
    input?.classList.remove('is-invalid');
    input?.removeAttribute('title');
  }

  form.addEventListener('submit', (e) => {
    let ok = true;
    [emailEl, discEl, gameEl, ageEl].forEach(clearError);

    if (!emailEl || !isEmail(emailEl.value)) { ok = false; showError(emailEl, 'Neteisingas el. paštas'); }
    if (!discEl || !isDiscord(discEl.value)) { ok = false; showError(discEl, 'Neteisingas Discord vardas'); }
    if (!gameEl || String(gameEl.value || '').trim().length < 2) { ok = false; showError(gameEl, 'Įveskite žaidimo vardą'); }

    const age = Number(ageEl?.value || 0);
    if (!ageEl || !(age >= 18 && age <= 100)) { ok = false; showError(ageEl, 'Amžius turi būti tarp 18 ir 100'); }

    if (!atLeastOneChecked()) {
      ok = false;
    }

    if (!ok) {
      e.preventDefault();
      alert('Patikrinkite formos laukus: kai kurie duomenys neteisingi arba neįvesti.');
      return;
    }

    // Sėkmės suvestinė — vietoje siuntimo (jei norite siųsti, pašalinkite e.preventDefault())
    e.preventDefault();

    const interests = Array.from(form.querySelectorAll('input[name="pomėgiai"]:checked, input[name="interesai[]"]:checked, input[name="interesai"]:checked'))
      .map(b => b.value).join(', ') || '(nepasirinkta)';

    const summary =
      `✅ Duomenys sėkmingai įvesti!\n\n` +
      `El. paštas: ${emailEl?.value || ''}\n` +
      `Discord: ${discEl?.value || ''}\n` +
      `Žaidimo vardas: ${gameEl?.value || ''}\n` +
      `Amžius: ${ageEl?.value || ''}\n` +
      `Domina: ${interests}`;

    alert(summary);
    form.reset();
  });

  [emailEl, discEl, gameEl, ageEl].forEach(el => {
    el?.addEventListener('input', () => clearError(el));
  });
})();